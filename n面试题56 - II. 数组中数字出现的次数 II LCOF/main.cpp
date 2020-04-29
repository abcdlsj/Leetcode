// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for(int i = 0; i < 32; i++) {
            int cnt = 0;
            for(auto num : nums) {
                if((1 << i & num) != 0) {
                    cnt++;
                }
            }
            if(cnt % 3 != 0) {
                ans += 1 << i;
            }
        }
        return ans;
    }
};
