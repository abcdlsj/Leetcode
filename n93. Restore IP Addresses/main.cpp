// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        vector<string> segments;
        backtrack(res, segments, s, 0);
        return res;
    }
    void backtrack(vector<string> &res, vector<string> &segments, const string &s, int start) {
        if(start == s.size() && segments.size() == 4) {
            string tmp = "";
            for(int i = 0; i < 3; i++) {
                tmp += segments[i] + '.';
            }
            tmp += segments[3];
            res.push_back(tmp);
        }

        for(int i = start; i < s.size() && i < start + 3 && segments.size() <= 4; i++) {
            string tmp = s.substr(start, i - start + 1);
            if((tmp[0] == '0' && tmp.size() > 1 ) || stoi(tmp) > 255 || stoi(tmp) < 0) {
                break;
            } else {
                segments.push_back(tmp);
                backtrack(res, segments, s, i + 1);
                segments.pop_back();
            }
        }
    }
};
