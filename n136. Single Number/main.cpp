// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans=0;
        if(nums.size()==1)
            return nums[0];
        for(int i=0;i<nums.size();i++)
            ans=ans^nums[i];
        return ans;
    }
};
