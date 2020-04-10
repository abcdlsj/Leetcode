// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    bool isPowerOfTwo(int n) {
        while(n>2) {
            if(n % 2 == 1) return false;        
            else n = n / 2;
        }
        if(n == 2 || n == 1) return true;
        else return false;
    }
};
