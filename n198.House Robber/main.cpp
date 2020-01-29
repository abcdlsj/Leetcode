// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==0) return 0;
        if(nums.size()==1) return nums[0];
        if(nums.size()==2) return max(nums[1],nums[0]);
        vector<int> cnt(nums);
        cnt[1]=max(cnt[1],cnt[0]);
        for(int i=2;i<nums.size();++i){
            cnt[i]=max(cnt[i-2]+cnt[i],cnt[i-1]);
        }
        return cnt[nums.size()-1];
    }
};
