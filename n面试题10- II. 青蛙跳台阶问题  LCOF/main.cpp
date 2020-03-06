// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    int numWays(int n) {
        if(n == 0 || n == 1) return 1;
        int a = 1, b = 1;
        for(int i = 2; i <= n; ++i) {
            a = a + b;
            b = a - b;
            a %= 1000000007;
        }
        return a;
    }
};
