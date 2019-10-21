// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.empty()) return 0;
        vector<int> cnt(nums);
        int maxn = nums[0];
        for(int i=1;i<nums.size();++i){
            cnt[i] = max(cnt[i-1]+nums[i],nums[i]);
            
            if(maxn<cnt[i])
                maxn = cnt[i];
        }
        return maxn;
     }
};
