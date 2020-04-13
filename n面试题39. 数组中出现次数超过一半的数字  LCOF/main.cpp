// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int res = 0, cnt = 0;
        for(auto num : nums) {
            if(cnt == 0) {
                res = num;
                cnt++;
            } else {
                res == num ? cnt++ : cnt--;
            }
        }
        return res;
    }
};
