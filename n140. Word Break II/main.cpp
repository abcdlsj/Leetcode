// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string, vector<string> > map;
        return backtrack(map, wordDict, s);
    }
    vector<string> backtrack(unordered_map<string, vector<string>> &map, vector<string> &wordDict, string s) {
        if (map.count(s)) return map[s];
        if (s.empty()) return {""};

        vector<string> res;
        for (auto word : wordDict) {
            if(s.substr(0, word.size()) != word) continue;
            vector<string> tmp = backtrack(map, wordDict, s.substr(word.size()));
            for(auto ele : tmp) {
                res.push_back(word + (ele.empty() ? "": " ") + ele);
            }
        }
        
        map[s] = res;
        return res;
    }
};
