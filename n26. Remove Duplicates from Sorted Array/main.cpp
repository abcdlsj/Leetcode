// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() < 2) return nums.size();

        int left = 0;
        for(int right = 1; right < nums.size(); right++) {
            if(nums[left] != nums[right]) 
                nums[++left] = nums[right];
        }
        
        return ++left;
    }
};
