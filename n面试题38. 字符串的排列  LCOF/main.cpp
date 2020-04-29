// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    vector<string> permutation(string s) {
        vector<string> res;
        vector<bool> vis(s.size(), false);
        string path;
        sort(s.begin(), s.end());
        backtrack(res, s, path, vis);
        return res;
    }
    void backtrack(vector<string> &res, string &s, string &path, vector<bool> &vis) {
        if(path.size() == s.size()) res.push_back(path);

        for(int i = 0; i < s.size(); i++) {
            if(vis[i] == true || (i > 0 && s[i] == s[i-1] && vis[i-1] == false)) continue;
            path.push_back(s[i]);
            vis[i] = true;
            backtrack(res, s, path, vis);
            vis[i] = false;
            path.pop_back();
        }
    }
};
