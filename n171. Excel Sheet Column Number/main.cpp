// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    int titleToNumber(string s) {
        long long ans = 0;
        for(auto ch : s) {
            ans = ans * 26 + ch - 'A' + 1;
        }
        return ans;
    }
};
