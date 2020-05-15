// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    string convert(string s, int numRows) {
        vector<string> strs(numRows);
        string res;
        if(s.empty() || numRows < 1) return res;
        if(numRows == 1) return s;
        int ans = 0, cur = 0;
        for(int i = 0; i < s.size(); i++) {
            ans = i / (numRows - 1), cur = i % (numRows - 1);
            if(ans % 2 == 0) {
                strs[cur].push_back(s[i]);
            } else {
                strs[numRows - cur - 1].push_back(s[i]);
            }
        }

        for(int i = 0; i < strs.size(); i++) {
            res += strs[i];
        }
        return res;
    }
};
