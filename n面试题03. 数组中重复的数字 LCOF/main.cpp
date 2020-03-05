// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        unordered_map<int, int> map;
        for(int i = 0; i < nums.size(); i++) {
            map[nums[i]]++;
            if(map[nums[i]] > 1) return nums[i];
        }
        return nums[0];
    }
};
