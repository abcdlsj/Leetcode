// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    int numSteps(string s) {
        int ans = 0;
        while(s.size() != 1) {
            if(s.back() == '0') {
                s = s.substr(0, s.size() - 1);
            } else {
                bool flag = true;
                int pos = -1;
                for(int i = s.size() - 1; i >= 0; i--) {
                    if(s[i] != '1') {
                        pos = i;
                        flag = false;
                        break;
                    }
                }
                if(flag) {
                    return ans + s.size() + 1;
                } else {
                    s[pos] = '1';
                    for(int i = pos + 1; i < s.size(); i++)
                        s[i] = '0';
                }
            }
            ans++;
        }
        return ans;
    }
};
