// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    int cuttingRope(int n) {
        if(n == 2) return 1;
        if(n == 3) return 2;
        
        long long ans = 1;
        while(n > 4) {
            n -= 3;
            ans *= 3;
            ans %= 1000000007;
        }

        return (int)(ans * n % 1000000007);
    }
};
