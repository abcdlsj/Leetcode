// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int left = 0, right = 0, match = 0;
        vector<int> res;
        unordered_map<char, int> window, needs;
        for(auto c : p) needs[c]++;
        while(right < s.size()) {
            char cright = s[right];
            if(needs.count(cright)) {
                window[cright]++;
                if(window[cright] == needs[cright]) match++;
            }
            while(match == needs.size()) {
                if(right - left + 1 == p.size()) res.push_back(left);
                char cleft = s[left];
                if(needs.count(cleft)) {
                    window[cleft]--;
                    if(window[cleft] < needs[cleft]) match--;
                }
                left++;
            }
            right++;
        }
        return res;
    }
};
