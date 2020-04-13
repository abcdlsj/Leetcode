// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string> res;
        for(auto w : words) {
            for(auto s : words) {
                if(s == w) continue;
                if(s.find(w) != -1) {
                    res.push_back(w);
                    break;
                } 
            }
        }
        return res;
    }
};
