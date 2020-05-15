// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res, segments;
        if(s.size() > 12 || s.size() < 4) return res;
        backtrack(res, segments, s, 0);
        return res;
    }
    void backtrack(vector<string> &res, vector<string> &segments, const string &s, int start) {
        if(start == s.size() && segments.size() == 4) {
            string ss;
            for(auto seg : segments) {
                ss += seg + '.';
            }
            res.push_back(ss.substr(0, ss.size() - 1));
        }

        for(int i = start; i < s.size() && i < start + 3 && segments.size() < 4; i++) {
            string ss = s.substr(start, i - start + 1);
            if((ss[0] == '0' && ss.size() != 1) || stoi(ss) > 255 || stoi(ss) < 0) {
                break;
            }
            else {
                segments.push_back(ss);
                backtrack(res, segments, s, i + 1);
                segments.pop_back();
            }
        }
    }
};
