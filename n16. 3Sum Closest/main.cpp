// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if(nums.size() == 3) return accumulate(nums.begin(), nums.end(), 0);
        int res, mingap = INT_MAX;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size() - 2; i++) {
            int left = i + 1, right = nums.size() - 1;
            while(left < right) {
                if(abs(nums[left] + nums[right] + nums[i] - target) < mingap) {
                    mingap = abs(nums[left] + nums[right] + nums[i] - target);
                    res = nums[left] + nums[right] + nums[i];
                } 
                if(nums[left] + nums[right] + nums[i] > target) right --;
                else left ++;
            }   
        }
        return res;
    }
};
