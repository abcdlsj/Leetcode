// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    bool canPermutePalindrome(string s) {
        if(s.length() == 1 || s.length() == 0) return true;
        vector<int> cnt(200, 0);
        int num = 0, odd = 0, even = 0;
        for(auto i : s) {
            if(cnt[i] == 0) num++;
            cnt[i] ++;
        }
        for(int i = 0; i < cnt.size(); i ++) {
            if (cnt[i] % 2 == 0 && cnt[i] != 0) even ++;
            if (cnt[i] % 2 == 1 && cnt[i] != 0) odd ++;
        }
        if(odd == 1 && even + odd == num) return true;
        else if (even == num) return true;
        return false;
    }
};
