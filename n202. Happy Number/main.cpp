// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    bool isHappy(int n) {
        int fast = squareNum(squareNum(n)), slow = squareNum(n);
        while(slow != fast) {
            slow = squareNum(slow);
            fast = squareNum(squareNum(fast));
        }
        return slow == 1;
    }
    int squareNum(int n) {
        int res = 0, num;
        while(n != 0) {
            num = n % 10;
            res += num * num;
            n /= 10;
        }
        return res;
    }
};
