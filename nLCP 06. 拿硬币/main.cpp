// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    int minCount(vector<int>& coins) {
        int ans = 0;
        for(auto coin : coins) {
            ans += coin / 2 + coin % 2;
        }
        return ans;
    }
};
