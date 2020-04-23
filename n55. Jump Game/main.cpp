// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxjump = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(i > maxjump) return false;
            maxjump = max(i + nums[i], maxjump);
        }
        return true;
    }
};
