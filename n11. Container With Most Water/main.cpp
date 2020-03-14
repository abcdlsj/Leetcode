// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
  int maxArea(vector<int> &height) {
    int MAX = 0;
    int i = 0, j = height.size() - 1;
    while (i < j) {
      if (height[i] < height[j]) {
        MAX = max(MAX, height[i] * (j - i));
        ++i;
      } else {
          MAX = max(MAX, height[j] * (j - i));
          --j;
      }

    }
    return MAX;
  }
};
