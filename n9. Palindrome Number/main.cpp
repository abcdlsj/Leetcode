// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        int rev = 0, tmp = x;
        while(tmp) {
            int pop = tmp % 10; tmp /= 10;
            if(rev > INT_MAX/10 || (rev == INT_MAX && pop > 7)) return false;
            if(rev < INT_MIN/10 || (rev == INT_MIN && pop < -8)) return false;
            rev = rev * 10 + pop;
        }   
        if(rev == x) return true;
        else return false;
    }
};
