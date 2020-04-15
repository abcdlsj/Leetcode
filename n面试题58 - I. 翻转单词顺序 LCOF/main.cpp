// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string ans = "", tmp;
        while(ss >> tmp) {
            ans.insert(0, tmp + " ");
        }
        return ans.size() ? string(ans.begin(), ans.end() - 1) : ans;
    }
};
