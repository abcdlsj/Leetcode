// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int end=n-1,start=0,mid;
        while(start<=end)
        {
            mid=(end-start)/2+start;
            if(target>nums[mid])
                start=mid+1;
            if(target<nums[mid])
                end=mid-1;
            if(target==nums[mid])
                return mid;
        }
        return -1;
    }
};
