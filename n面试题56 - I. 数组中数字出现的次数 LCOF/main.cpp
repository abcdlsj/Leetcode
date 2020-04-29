// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        int xorNum = 0, ans1 = 0;
        for(auto num : nums) {
            xorNum ^= num;
        }
        // 得到最后一个 1
        int flag = xorNum & (-xorNum);
        for(auto num : nums) {
            if((flag & num) != 0) {
                ans1 ^= num;
            }
        }
        return {ans1, xorNum ^ ans1};
    }
};
