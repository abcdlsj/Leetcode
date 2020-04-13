// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size() == 0) return 0;
        return binarysearch(nums, target + 0.5) - binarysearch(nums, target - 0.5);
    }
    int binarysearch(vector<int>& nums, double target) {
        int left = 0, right = nums.size() - 1;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(target > nums[mid]) left = mid + 1;
            if(target < nums[mid]) right = mid - 1;
        }
        return left;
    } 
};
