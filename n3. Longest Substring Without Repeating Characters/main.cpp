// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> map;
        int start = 0, maxlen = 0;
        for(int i = 0; i < s.size(); i++) {
            if(map.count(s[i]) != 0) {
                start = max(start, map[s[i]] + 1);
            }
            maxlen = max(maxlen, i - start + 1);
            map[s[i]] = i;
        }
        return maxlen;
    }
};
