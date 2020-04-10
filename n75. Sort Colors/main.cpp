// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int pre = 0, cur = 0, fin = nums.size() - 1;
        while(cur <= fin) {
            if(nums[cur] == 2) {
                swap(nums[cur], nums[fin]);
                fin --;
            }
            else if(nums[cur] == 0) {
                swap(nums[pre], nums[cur]);
                cur ++;
                pre ++;
            }
            else cur ++;
        } 
    }
};
