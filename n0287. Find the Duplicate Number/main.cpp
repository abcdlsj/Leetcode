// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size(),res[n+10];
        memset(res,0,sizeof(res));
        for(int i=0;i<n;i++)
        {
            if(res[nums[i]]==1)
                return nums[i];
            res[nums[i]]=1;
        }
        return 0;
    }
};
