// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    string minWindow(string s, string t) {
        int left = 0, right = 0, match = 0, start = 0, minlen = INT_MAX;
        unordered_map<char, int> windows, needs;
        for(auto c : t) needs[c]++;
        while(right < s.size()) {
            char cright = s[right];
            if(needs.count(cright)) {
                windows[cright]++;
                if(windows[cright] == needs[cright]) match++;
            }
            while(match == needs.size()) {
                if(right - left + 1 < minlen) {
                    start = left;
                    minlen = right - left + 1;
                }
                char cleft = s[left];
                if(needs.count(cleft)) {
                    windows[cleft]--;
                    if(windows[cleft] < needs[cleft]) match--;
                }
                left++;
            }
            right++;
        }
        return minlen == INT_MAX ? "" : s.substr(start, minlen);
    }
};
