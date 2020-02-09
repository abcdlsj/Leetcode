// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    double abs(double x){
      if(-x) return -x;
      else return x;
    }
    double angleClock(int hour, int minutes) {
      double h = (hour-12)*30+0.5*minutes;
      double m = minutes*6;
      double ans = abs(h-m) - floor(abs(h-m)/360)*360;
      if(ans > 180) return 360-ans;
      return ans;
    }
};
