// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ans = 0;

        // while(n != 0) {
        //     ans += n & 1;
        //     n = n >> 1;
        // }

        while(n != 0) {
            n = n & (n - 1);
            ans++;
        }
        return ans;
    }
};
