// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    bool canConstruct(string s, int k) {
        if(k > s.length()) return false;
        if(k == s.length()) return true;
        vector<int> cnt(26, 0);
        int t = 0;
        for(auto c : s) cnt[c - 'a'] ^= 1;
        for(auto c : cnt) {
            if(c % 2 == 1)  t++;
        }
        if(t > k) return false;
        return true;
    }
};
