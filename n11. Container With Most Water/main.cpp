// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
  public:
    int maxArea(vector<int>& height) {
      int MAX = 0, left = 0, right = height.size() - 1;
      while(left < right) {
        if(height[left] < height[right]) {
          MAX = max(MAX, height[left] * (right - left));
          left ++;
        }
        else {
          MAX = max(MAX, height[right] * (right - left));
          right --;
        }
      }
      return MAX;
    }
  };

