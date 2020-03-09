// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
  int reverse(int x) {
    int res = 0; // res表示结果

    while (x != 0) {
      if (res > INT_MAX / 10)
        return 0; //注意：看ps
      if (res < INT_MIN / 10)
        return 0; //判断是否将要发生越界
      res *= 10;
      res = res + x % 10;
      x = x / 10;
    }
    return res;
  }
};
