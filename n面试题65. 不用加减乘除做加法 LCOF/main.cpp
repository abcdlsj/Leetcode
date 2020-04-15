// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    int add(int a, int b) {
        while(b != 0) {
            int tmpa = a ^ b;
            int tmpb = ((unsigned int)(a & b) << 1);
            a = tmpa;
            b = tmpb;
        }
        return a;
    }
};
