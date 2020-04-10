// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    bool CheckPermutation(string s1, string s2) {
        vector<int> cnt(200, 0);
        if(s1.size() != s2.size()) return false;
        for(int i = 0; i < s1.size(); i++) {
            cnt[s1[i]] ++;
            cnt[s2[i]] --;
        }
        for(auto i : cnt) {
            if(i != 0) return false; 
        }
        return true;
    }
};
