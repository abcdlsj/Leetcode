// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    string sortString(string s) {
        vector<int> cnt(26);
        string res;
        for(auto c : s) cnt[c - 'a']++;
        auto max = *max_element(cnt.begin(), cnt.end());
        int re = 1;
        for(int time = 0; time < max; ++time) {
            if(re == 1) {
                for(int i = 0; i < 26; ++i) {
                    if(cnt[i]) {
                        res += 'a' + i;
                        cnt[i]--;
                    }
                }
            }
            if(re == -1) {
                for(int i = 25; i >= 0; --i) {
                    if(cnt[i]) {
                        res += 'a' + i;
                        cnt[i]--;
                    }
                }
            }
            re = -re;
        }
        return res;
    }
};
