// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    int findTheLongestSubstring(string s) {
        int n = s.size();
        int res = 0;
        string zero = "aeiou";
        vector<int> index(1 << 5, INT_MAX);
        index[0] = 0;
        int stage = 0;
        for(int i = 1; i <= n; i++) {
            for(int j = 0; j < 5; j++) 
                if(s[i - 1] == zero[j])
                    stage ^= (1 << j);
            index[stage] = min(index[stage], i);
            res = max(res, i - index[stage]);
        }
        return res;
    }
};
