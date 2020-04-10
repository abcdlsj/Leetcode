// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        return maxarray(nums, 0, nums.size() - 1);
    }
    int maxarray(vector<int> &nums, int left, int right) {
        if(left == right) return nums[left];
        int mid = left + (right - left) / 2;
        int leftsum = maxarray(nums, left, mid);
        int rightsum = maxarray(nums, mid + 1, right);
        int crosssum = maxcross(nums, left, right, mid);
        int res = max(max(leftsum, rightsum), crosssum);
        return res;
    }
    int maxcross(vector<int> &nums, int left, int right, int mid) {
        int leftsum = INT_MIN, rightsum = INT_MIN, sum = 0;
        for(int i = mid; i >= left; i--) {
            sum += nums[i];
            leftsum = max(leftsum, sum);
        }
        sum = 0;
        for(int i = mid + 1; i <= right; i++) {
            sum += nums[i];
            rightsum = max(rightsum, sum);
        }
        return leftsum + rightsum;
    }
};
