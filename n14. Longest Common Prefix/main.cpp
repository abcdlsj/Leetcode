// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0) return "";
        if(strs.size() == 1) return strs[0];
        string res = strs[0];
        for(auto str : strs) {
            while(str.find(res, 0) == -1 || str.find(res, 0) != 0){
                res = res.substr(0, res.length() - 1);
            }
        }
        return res;
    }
};

