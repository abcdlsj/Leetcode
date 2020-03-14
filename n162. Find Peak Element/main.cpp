// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    // int binarysearch(vector<int> nums, int left, int right) {
    //     if(left >= right) return left;
    //     int mid = left + (right - left) / 2;
    //     if(nums[mid] > nums[mid + 1])
    //         return binarysearch(nums, left, mid);
    //     else
    //         return binarysearch(nums, mid + 1, right);
    // }
    int findPeakElement(vector<int>& nums) {
        // 递归
        // return binarysearch(nums, 0, nums.size() - 1);
        
        // 迭代
        int left = 0, right = nums.size() - 1;
        int mid = 0;
        while(left < right) {
            mid = left + (right - left) / 2;
            if(nums[mid] > nums[mid + 1])
                right = mid;
            else
                left = mid + 1;
        }
        return left;
    }
};
