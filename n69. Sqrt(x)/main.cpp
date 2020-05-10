// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    int mySqrt(int x) {
        int low = 0, hign = x, mid, ans;
        while(low <= hign) {
            mid = low + (hign - low) / 2;
            if((long long)mid * mid <= x) {
                ans = mid;
                low = mid + 1;
            } else {
                hign = mid - 1;
            }
        }
        return ans;
    }
};
