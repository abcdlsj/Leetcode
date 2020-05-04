// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    double myPow(double base, int n) {
        double res = 1;
        int exp = n;
        while(exp) {
            if(exp & 1) res = res * base;
            base = base * base;
            exp = exp / 2;
        }
        return n > 0 ? res : 1.0 / res;
    }
};
