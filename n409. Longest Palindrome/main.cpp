// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    int longestPalindrome(string s) {
        int count = 0; //记录奇数的个数
        vector<int> cnt(128);
        for(auto c : s) cnt[c] ++;
        for(auto c : cnt) count += (c % 2);
        return count == 0 ? s.size(): (s.size() - count + 1);
    }
};
