// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    string reverseLeftWords(string s, int n) {
        string cnt = s + s;
        return string(cnt.begin() + n, cnt.begin() + n + s.size());
    }
};
