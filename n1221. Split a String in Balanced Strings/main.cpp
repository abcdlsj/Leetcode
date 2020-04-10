// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    int balancedStringSplit(string s) {
        int cnt = 0, ans = 0;
        for(auto ch : s) {
            if(ch == 'R') {
                cnt++;
            } else {
                cnt--;
            }
            if(cnt == 0) {
                ans++;
            }
        }
        return ans;
    }
};
