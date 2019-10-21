// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

/*
 * @lc app=leetcode.cn id=35 lang=cpp
 *
 * [35] 搜索插入位置
 */
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n=nums.size();
        if(n==0) return 0;
        int ans;
        for(int i=0;i<n;i++)
        {
            if(target==nums[i]) return i;
            if(target<nums[0]) return 0;
            if(target>nums[i]) ans=i+1;
            if(target<nums[i]) return ans;
        }
        return n;
    }
};


