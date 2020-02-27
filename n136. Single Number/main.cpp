// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int i;
        if(nums.size()<=2)
            return nums[0];
        for(i=0;i+2<nums.size();i+=2)
            if(nums[i]!=nums[i+1])
                return nums[i];
        return nums[nums.size()-1];
    }
};
