// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        if(nums.size() == 1) return nums[0];
        if(nums.size() == 2) return max(nums[0], nums[1]);
        return max(rob2(nums, 0, nums.size() - 2), rob2(nums, 1, nums.size() - 1));
    }
    int rob2(vector<int>& nums, int start, int end) {
        vector<int> cnt(nums);
        cnt[start+1] = max(cnt[start], cnt[start+1]);
        for(int i = start+2; i <= end; i++) {
            cnt[i] = max(cnt[i] + cnt[i-2], cnt[i-1]);
        }
        return cnt[end];
    }
};
