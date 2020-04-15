// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1, sum;
        while(left < right) {
            sum = nums[left] + nums[right];
            if(sum < target) {
                left++;
            } else if(sum > target){
                right--;
            } else {
                return {nums[left], nums[right]};
            }
        }
        return {};
    }
};
