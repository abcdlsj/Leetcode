# -*- coding: utf-8 -*-
"""
Created on Sat Sep 14 14:15:12 2019

@author: lison
"""

#!/usr/bin/env python
# encoding: utf-8
import requests, os
import requests_cache
import re, threading
import html
import subprocess, time
from requests.utils import requote_uri
from collections import Counter
from datetime import datetime
from json.decoder import JSONDecodeError

CODE_TEMPLATE = \
"""// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

{code}
"""

REPO_README_TEMPLATE = """
## Leetcode
目前已解决的题目（{solv_question_num} 个，其中简单{easy_num} 个，中等{medium_num} 个， 困难{hard_num} 个）：
{solv_question_list}
"""

QUESTION_TEMPLATE = \
"""# {question_name} {question_level}
- 题目地址: [{question_url}]({question_url})
- 执行时间: {runtime}
- 内存消耗: {mem_usage}
- 通过日期: {time}

## 题目内容
{question_content}

## 解法
```{lang}
{code}
```"""

class Leetcode:
    LEETCODE_URL = 'https://leetcode-cn.com'
    LEETCODE_LIST_URL = 'https://leetcode-cn.com/api/problems/all/'
    LEETCODE_GRAPHQL = 'https://leetcode-cn.com/graphql'
    REPO_URL = 'https://github.com/abcdlsj/Leetcode'
    def __init__(self):
        self.cookies = "_uab_collina=156785742233246778992492; Hm_lvt_fa218a3ff7179639febdb15e372f411c=1567906479; Hm_lpvt_fa218a3ff7179639febdb15e372f411c=1567906479; csrftoken=yqqtg6tKOulAmy5oaEQJq3aFnre2m3uaaPn0h8n77oeSWIQTxgkRY8aleUgrm5xp; LEETCODE_SESSION=eyJ0eXAiOiJKV1QiLCJhbGciOiJIUzI1NiJ9.eyJfYXV0aF91c2VyX2lkIjoiMTQxNzkzIiwiX2F1dGhfdXNlcl9iYWNrZW5kIjoiZGphbmdvLmNvbnRyaWIuYXV0aC5iYWNrZW5kcy5Nb2RlbEJhY2tlbmQiLCJfYXV0aF91c2VyX2hhc2giOiJkZjNmODRmOTU5ODUzNDlhNTYzNDI2Mjg4Y2UxMjNmM2Y1ZmQxYzA4IiwiaWQiOjE0MTc5MywiZW1haWwiOiJsaXNvbmdqaWFuc2h1YWlAZ21haWwuY29tIiwidXNlcm5hbWUiOiJhYmNkbHNqIiwidXNlcl9zbHVnIjoiYWJjZGxzaiIsImF2YXRhciI6Imh0dHBzOi8vYXNzZXRzLmxlZXRjb2RlLWNuLmNvbS9hbGl5dW4tbGMtdXBsb2FkL3VzZXJzL29jdG9wdXNwYWxtL2F2YXRhcl8xNTQzNTQwODU3LnBuZyIsInBob25lX3ZlcmlmaWVkIjp0cnVlLCJ0aW1lc3RhbXAiOiIyMDE5LTA5LTE0IDAxOjIxOjA5LjE2NzkzMCswMDowMCIsIlJFTU9URV9BRERSIjoiMTcyLjIxLjEuMTUxIiwiSURFTlRJVFkiOiI0NzFlNGI4NmUzNTYwYzZmZWI0NzRkZWYwOTgxNjliNiIsIl9zZXNzaW9uX2V4cGlyeSI6MTIwOTYwMH0.63_7YEaZdSavinhXTIP9bJJwskIW9FYWn4bXrbKu7_4"
        self.headers = {
                'accept':"*/*",
                'accept-encoding':"gzip, deflate, br",
                'accept-language':"zh-CN,zh;q=0.9",
                'user-agent':"Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/76.0.3809.132 Safari/537.36",
                'content-type':"application/json",
                'cookie':self.cookies,
                }
        self.cached_solved_quest = {}

    def get_solved_list(self):
        with requests_cache.disabled():
            return [{
                "question_slug": v['stat']['question__title_slug'],
                "question_id": v['stat']['frontend_question_id'], # 用页面上显示的id
                "question_title": v['stat']['question__title'],
                "question_difficulty": v['difficulty']['level']
                } for v in
                    requests.get(Leetcode.LEETCODE_LIST_URL, headers=self.headers).json()['stat_status_pairs']
                if v['status'] == 'ac'
            ]

    def get_submit_list(self, question_slug):
        with requests_cache.disabled():
            data = '{"operationName":"Submissions","variables":{"offset":0,"limit":0,"lastKey":null,"questionSlug":"%s"},"query":"query Submissions($offset: Int!, $limit: Int!, $lastKey: String, $questionSlug: String!) {\\n  submissionList(offset: $offset, limit: $limit, lastKey: $lastKey, questionSlug: $questionSlug) {\\n    lastKey\\n    hasNext\\n    submissions {\\n      id\\n      statusDisplay\\n      lang\\n      runtime\\n      timestamp\\n      url\\n      isPending\\n      memory\\n      __typename\\n    }\\n    __typename\\n  }\\n}\\n"}' % question_slug
            submit_list = [item for item in
                           requests.post(Leetcode.LEETCODE_GRAPHQL,
                                         headers=self.headers,
                                         data=data).json()['data']['submissionList']['submissions']
                           if item['statusDisplay'].lower() == 'accepted']
            return submit_list

    def get_source(self, url): # /submissions/detail/14313499/
        req_url = self.LEETCODE_URL + url
        try:
            src = re.search('submissionCode: \'(.*)\',', requests.get(req_url, headers=self.headers).text).group(1)
            return src.encode('cp1252', 'backslashreplace').decode('unicode-escape')
        except AttributeError:
            pass

    def get_question_content(self, question_slug): # /problems/number-of-enclaves/
        data = '{"operationName":"questionData","variables":{"titleSlug":"%s"},"query":"query questionData($titleSlug: String!) {\\n  question(titleSlug: $titleSlug) {\\n    questionId\\n    questionFrontendId\\n    boundTopicId\\n    title\\n    titleSlug\\n    content\\n    translatedTitle\\n    translatedContent\\n    isPaidOnly\\n    difficulty\\n    likes\\n    dislikes\\n    isLiked\\n    similarQuestions\\n    contributors {\\n      username\\n      profileUrl\\n      avatarUrl\\n      __typename\\n    }\\n    langToValidPlayground\\n    topicTags {\\n      name\\n      slug\\n      translatedName\\n      __typename\\n    }\\n    companyTagStats\\n    codeSnippets {\\n      lang\\n      langSlug\\n      code\\n      __typename\\n    }\\n    stats\\n    hints\\n    solution {\\n      id\\n      canSeeDetail\\n      __typename\\n    }\\n    status\\n    sampleTestCase\\n    metaData\\n    judgerAvailable\\n    judgeType\\n    mysqlSchemas\\n    enableRunCode\\n    enableTestMode\\n    envInfo\\n    __typename\\n  }\\n}\\n"}' % question_slug
        question_content = requests.post(self.LEETCODE_GRAPHQL,
                                         headers=self.headers,
                                         data=data).json()['data']['question']
        return question_content

    def output_source(self, lang='cpp', lang_suffix='cpp', max_threads=8):
        self.get_cached_solved_ques()
        solved_list = self.get_solved_list()
        threads = []
        for idx, question in enumerate(solved_list):
            print("processing: {}. {} ({}/{})".format(question["question_id"],
                                                      question["question_title"],
                                                      idx + 1, len(solved_list)))
            if question["question_title"] in self.cached_solved_quest:
                print("cached: ", question["question_title"])
                continue

            def process_submit_list(question_):
                try:
                    submit_list = self.get_submit_list(question_["question_slug"])
                except JSONDecodeError:
                    return
                for submit in submit_list:
                    if submit["lang"] == lang:
                        src = self.get_source(submit['url'])
                        if not src: continue

                        question_content = self.get_question_content(question_["question_slug"])
                        if question_content['translatedContent'] is None: continue
                        src = CODE_TEMPLATE.format(code=src)
                        dir_name = "n{}. {}".format(question_["question_id"], question_["question_title"])
                        if not os.path.exists(dir_name):
                            os.mkdir(dir_name)
                        with open(os.path.join(dir_name, "main.{}".format(lang_suffix)), "w",encoding='utf-8') as f:
                            f.write(src)

                        with open(os.path.join(dir_name, "README.md"), "w",encoding='utf-8') as f:
                            f.write(QUESTION_TEMPLATE.format(question_name = question_["question_title"],
                                                             question_level = '*' * question_["question_difficulty"],
                                                             question_url = self.LEETCODE_URL + "/problems/{}".format(question_["question_slug"]),
                                                             runtime = submit["runtime"],
                                                             mem_usage = submit["memory"],
                                                             time = datetime.fromtimestamp(int(submit["timestamp"])).strftime("%Y-%m-%d %H:%M"),
                                                             lang = lang,
                                                             question_content=html.unescape(question_content['translatedContent']).replace('<p>\xa0</p>', ''),
                                                             code = src))
                        break # 只取最新的(第一条就是)
            while len(threads) >= max_threads:
                for thread in threads:
                    if not thread.is_alive():
                        threads.remove(thread)
                time.sleep(0.5)

            thread = threading.Thread(target=process_submit_list, args=(question,), daemon=True)
            thread.start()
            threads.append(thread)

        # 最后检查存活线程
        while len(threads) > 0:
            for thread in threads:
                if not thread.is_alive():
                    threads.remove(thread)

        self.__generate_readme()

    def get_cached_solved_ques(self):
        if not os.environ.get('CACHED_SOLVED_QUES'): return
        pattern_name = re.compile('n(\d+)\. (.*)')
        for dir_name in os.listdir('.'):
            if not pattern_name.match(dir_name): continue
            self.cached_solved_quest[pattern_name.search(dir_name).group(2)] = True

    def __generate_readme(self):
        pattern_name = re.compile('n(\d+)\. (.*)')
        question_level = {
            1: 0, 2: 0, 3: 0
        }
        question_list = []
        for dir in os.listdir('.'):
            if not pattern_name.match(dir): continue
            # 更新难度
            level = open('{}/README.md'.format(dir), 'r',encoding='utf-8').readline().count('*')
            question_level[level] += 1
            question_list.append('{} {}'.format(dir, '*' * level))


        question_list.sort(key=lambda q: int(re.search(r"(\d+)\..*", q).group(1)))
        question_list = '\n'.join(
            map(lambda u: "- [{}]({})".format(
                u.lstrip('n0'), requote_uri(
                    (Leetcode.REPO_URL + '/tree/master/{}'.format(u.replace('*', ''))).strip()
                )
            ) , question_list)
        )
        with open("README.md", "w",encoding='utf-8') as f:
            f.write(REPO_README_TEMPLATE.format(solv_question_num=sum(question_level.values()),
                                                easy_num=question_level[1],
                                                medium_num=question_level[2],
                                                hard_num=question_level[3],
                                                solv_question_list=question_list))


if __name__ == '__main__':
    requests_cache.install_cache('leetcode')
    lc = Leetcode()

    lc.output_source()

    subprocess.run(["git", "add", "."])
    subprocess.run(["git", "commit", "-m", "commit by leetcode_.py @abcdlsj at {}".format(datetime.now().strftime("%Y-%m-%d %H:%M"))])
    subprocess.run(["git", "push", "-f", "origin", "master"])
