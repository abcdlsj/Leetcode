// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    vector<int> shortestSeq(vector<int>& big, vector<int>& small) {
        int left = 0, right = 0, start = 0, minlen = INT_MAX, match = 0;
        vector<int> res;
        unordered_map<int, int> window, needs;
        for(auto num : small) needs[num]++;
        while(right < big.size()) {
            int numright = big[right];
            if(needs.count(numright)) {
                window[numright]++;
                if(window[numright] == needs[numright]) match++;
            }
            while(match == needs.size()) {
                if(right - left + 1 < minlen) {
                    start = left;
                    minlen = right - left + 1;
                }
                int numleft = big[left];
                if(needs.count(numleft)) {
                    window[numleft]--;
                    if(window[numleft] < needs[numleft]) match--;
                }
                left++;
            }
            right++;
        }
        if(minlen != INT_MAX) {
            res.push_back(start);
            res.push_back(start + minlen - 1);
        }
        return res;
    }
};
