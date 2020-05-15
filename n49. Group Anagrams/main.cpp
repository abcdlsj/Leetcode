// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> map;
        for(auto str : strs) {
            string ss = str;
            sort(str.begin(), str.end());
            map[str].push_back(ss);
        }
        vector<vector<string>> res;
        for(pair<string, vector<string>> x : map) {
            res.push_back(x.second);
        }
        return res;
    }
};
