// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        map<int,int> re;
        int ans;
        for(int i=0;i<n;i++)
        {
            re[nums[i]]++;
            if(re[nums[i]]>(n/2))
            {
                ans=nums[i];
                break;
            }
        }
        return ans;
    }
};
