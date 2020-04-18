// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    int countPrimes(int n) {
        vector<bool> cnt(n, true);
        int ans = 0;
        for(int i = 2; i < n; i++) {
            if(cnt[i]) {
                ans++;
                for(int j = i + i; j < n; j += i) {
                    cnt[j] = false;
                }
            }
        }
        return ans;
    }
};
