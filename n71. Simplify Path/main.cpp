// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    string simplifyPath(string path) {
        string res = "", dir = "";
        vector<string> vec;
        path += "/";
        for(auto c : path) {
            if(c == '/') {
                if(!vec.empty() && dir == "..") vec.pop_back();
                else if(!dir.empty() && dir != ".." && dir != ".") vec.push_back(dir);
                dir.clear();
            } else {
                dir += c;
            }
        }
        if(vec.empty()) return "/";
        for(auto s : vec) {
            res += '/' + s;
        }
        return res;
    }
};
