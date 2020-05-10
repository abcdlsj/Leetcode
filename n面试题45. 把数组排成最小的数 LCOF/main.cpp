// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    string minNumber(vector<int>& nums) {
        vector<string> strs;
        string res;
        for(auto num : nums) {
            strs.push_back(to_string(num));
        }
        sort(strs.begin(), strs.end(), compare);
        for(auto s : strs) {
            res += s;
        }
        return res;
    }
    static bool compare(const string &a, const string &b) {
        return a + b < b + a;
    }
};
