// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    string simplifyPath(string path) {
        stringstream is(path);
        string tmp = "", res = "";
        vector<string> strs;
        while(getline(is, tmp, '/')) {
            if(tmp == "" || tmp == ".") continue;
            else if(tmp == ".." && !strs.empty()) strs.pop_back();
            else if(tmp != "..") strs.push_back(tmp);
        }
        for(auto str : strs) {
            res += "/" + str;
        }
        if(strs.empty()) res += "/";
        return res;
    }
};
