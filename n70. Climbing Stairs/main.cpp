// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    int climbStairs(int n) {
        if(n == 1 || n == 2) return n;
        vector<int> cnt(n + 1, 0);
        cnt[1] = 1, cnt[2] = 2;
        for(int i = 3; i <= n; i++) {
            cnt[i] = cnt[i-1] + cnt[i-2];
        }
        return cnt[n];
    }
};
