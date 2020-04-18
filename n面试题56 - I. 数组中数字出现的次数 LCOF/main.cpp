// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        int towNumsXor = 0, ans1 = 0;
        for(auto num : nums) towNumsXor ^= num;
        int flag = towNumsXor & (-towNumsXor); //得到一个 1
        for(auto num : nums) {
            if((flag & num) != 0) {
                ans1 ^= num;
            }
        }
        return {ans1, towNumsXor ^ ans1};
    }
};
