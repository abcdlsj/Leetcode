// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> path;
        backtrack(res, path, s, 0);
        return res;
    }
    void backtrack(vector<vector<string>> &res, vector<string> &path, const string &s, int start) {
        if(start == s.size()) res.push_back(path);

        for(int i = start; i < s.size(); i++) {
            string ss = s.substr(start, i - start + 1);
            if(ispa(ss)) {
                path.push_back(ss);
                backtrack(res, path, s, i + 1);
                path.pop_back();
            } else {
                continue;
            }
        }
    }
    bool ispa(string s) {
        return s == string(s.rbegin(), s.rend());
    }
};
