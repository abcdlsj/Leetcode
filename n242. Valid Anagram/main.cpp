// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> ss(26,0);
        vector<int> tt(26,0);
        if(s.size() != t.size()) return false;
        for(int i = 0; i < s.size(); i++) {
            ss[s[i] - 'a'] ++;
            tt[t[i] - 'a'] ++;
        }
        for(int i = 0; i < 26; i++) {
            if(ss[i] != tt[i]) return false;
        }
        return true;
    }
};
