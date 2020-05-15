// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0 || nums.size() == 1) return nums.size();
        int left = 0, cur = 0;
        while(cur < nums.size()) {
            if(nums[left] != nums[cur]) {
                nums[++left] = nums[cur++];
            } else {
                cur++;
            }
        }
        return ++left;
    }
};
