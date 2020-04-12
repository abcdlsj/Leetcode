// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size(), MAX = nums[0];
        vector<int> cnt(nums);
        for(int i = 1; i < n; i++) {
            cnt[i] = max(cnt[i - 1] + cnt[i], cnt[i]);
            if(cnt[i] > MAX) MAX = cnt[i];
        }
        return MAX;
    }
};
