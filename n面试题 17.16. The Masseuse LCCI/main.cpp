// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    int massage(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        if(nums.size() == 1) return nums[0];
        if(nums.size() == 2) return max(nums[0], nums[1]);
        vector<int> cnt(nums);
        cnt[1] = max(cnt[0], cnt[1]);
        for(int i = 2; i < nums.size(); i++) {
            cnt[i] = max(cnt[i] + cnt[i-2], cnt[i-1]);
        }
        return cnt[nums.size() - 1];
    }
};
