// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> cnt(n, 0);
        cnt[0] = 1;
        int x = 0, y = 0, z = 0;
        for(int i = 1; i < n; i++) {
            cnt[i] = min(cnt[x] * 2, min(cnt[y] * 3, cnt[z] * 5));
            if(cnt[i] == cnt[x] * 2) x++;
            if(cnt[i] == cnt[y] * 3) y++;
            if(cnt[i] == cnt[z] * 5) z++;
        }
        return cnt[n - 1];
    }
};
