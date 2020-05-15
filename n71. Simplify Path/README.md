# Simplify Path **
- 题目地址: [https://leetcode-cn.com/problems/simplify-path](https://leetcode-cn.com/problems/simplify-path)
- 执行时间: 16 ms
- 内存消耗: 8 MB
- 通过日期: 2020-05-12 11:05

## 题目内容
<p>以 Unix 风格给出一个文件的<strong>绝对路径</strong>，你需要简化它。或者换句话说，将其转换为规范路径。</p>

<p>在 Unix 风格的文件系统中，一个点（<code>.</code>）表示当前目录本身；此外，两个点 （<code>..</code>） 表示将目录切换到上一级（指向父目录）；两者都可以是复杂相对路径的组成部分。更多信息请参阅：<a href="https://blog.csdn.net/u011327334/article/details/50355600" target="_blank">Linux / Unix中的绝对路径 vs 相对路径</a></p>

<p>请注意，返回的规范路径必须始终以斜杠 <code>/</code> 开头，并且两个目录名之间必须只有一个斜杠 <code>/</code>。最后一个目录名（如果存在）<strong>不能</strong>以 <code>/</code> 结尾。此外，规范路径必须是表示绝对路径的<strong>最短</strong>字符串。</p>



<p><strong>示例 1：</strong></p>

<pre><strong>输入："</strong>/home/"
<strong>输出："</strong>/home"
<strong>解释：</strong>注意，最后一个目录名后面没有斜杠。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入："</strong>/../"
<strong>输出："</strong>/"
<strong>解释：</strong>从根目录向上一级是不可行的，因为根是你可以到达的最高级。
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入："</strong>/home//foo/"
<strong>输出："</strong>/home/foo"
<strong>解释：</strong>在规范路径中，多个连续斜杠需要用一个斜杠替换。
</pre>

<p><strong>示例 4：</strong></p>

<pre><strong>输入："</strong>/a/./b/../../c/"
<strong>输出："</strong>/c"
</pre>

<p><strong>示例 5：</strong></p>

<pre><strong>输入："</strong>/a/../../b/../c//.//"
<strong>输出："</strong>/c"
</pre>

<p><strong>示例 6：</strong></p>

<pre><strong>输入："</strong>/a//b////c/d//././/.."
<strong>输出："</strong>/a/b/c"</pre>


## 解法
```cpp
// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    string simplifyPath(string path) {
        string res = "", dir = "";
        vector<string> vec;
        path += "/";
        for(auto c : path) {
            if(c == '/') {
                if(!vec.empty() && dir == "..") vec.pop_back();
                else if(!dir.empty() && dir != ".." && dir != ".") vec.push_back(dir);
                dir.clear();
            } else {
                dir += c;
            }
        }
        if(vec.empty()) return "/";
        for(auto s : vec) {
            res += '/' + s;
        }
        return res;
    }
};

```