// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int cnt = 0;
        for(auto i : nums) 
            cnt ^= i;
        return cnt;
    }
};
