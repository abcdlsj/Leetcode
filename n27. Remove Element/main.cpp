// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int pre = 0, cur = 0;
        while(cur < nums.size()) {
            if(nums[cur] == val) {
                cur++;
            } else {
                nums[pre++] = nums[cur++];
            }
        }
        return pre;
    }
};
