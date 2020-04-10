// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> path;
        if(s.size() == 0) return res;
        backtrack(res, path, 0, s);
        return res;
    }
    void backtrack(vector<vector<string>> &res, vector<string> &path, int start, const string &s) {
        if(start >= s.size()) {
            res.push_back(path);
            return;
        }
        string tmp = "";
        for(int i = start; i < s.size(); i++) {
            tmp.push_back(s[i]);
            if(ispalindrome(tmp)) {
                path.push_back(tmp);
                backtrack(res, path, i + 1, s);
                path.pop_back();
            }
        }
    }
    bool ispalindrome(const string &s) {
        return s == string(s.rbegin(), s.rend());
    }
};
