// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    int binarysearch(vector<int> nums, int left, int right) {
        if(left >= right) return left;
        int mid = left + (right - left) / 2;
        if(nums[mid] > nums[mid + 1])
            return binarysearch(nums, left, mid);
        else
            return binarysearch(nums, mid + 1, right);
    }
    int findPeakElement(vector<int>& nums) {
        return binarysearch(nums, 0, nums.size() - 1);
    }
};
