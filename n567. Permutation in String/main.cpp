// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()) return false;
        vector<int> cnt(26, 0);
        for(auto c : s1) cnt[c - 'a']++;
        for(int i = 0; i < s2.size() - s1.size() + 1; i++) {
            if(cnt[s2[i] - 'a'] != 0) {
                vector<int> cntc(cnt.begin(), cnt.end());
                for(int j = i + s1.size() - 1; j >= i; j--) {
                    if(cntc[s2[j] - 'a'] != 0) cntc[s2[j] - 'a']--;
                }
                if(accumulate(cntc.begin(), cntc.end(), 0) == 0) return true;
            }
        }
        return false;
    }
};
