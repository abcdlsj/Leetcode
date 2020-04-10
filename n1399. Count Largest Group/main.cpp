// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    int gethe(int n) {
        int res = 0;
        while(n > 0) {
            res += n % 10;
            n = n / 10;
        }
        return res;
    }
    int countLargestGroup(int n) {
        vector<int> cnt(37, 0);
        int ans = 0, MAX = INT_MIN;
        for(int i = 1; i <= n; i++) {
            cnt[gethe(i)] ++;
            MAX = max(MAX, cnt[gethe(i)]);
        }
        for(auto c : cnt) {
            if (c == MAX) ans++;
        }
        return ans;
    }
};
