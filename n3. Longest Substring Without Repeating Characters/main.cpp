// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> map;
        int start = 0, ans = 0;
        for(int i = 0; i < s.size(); i++){
            if(map.find(s[i]) != map.end()) {
                start = max(map[s[i]] + 1, start);
            }
            ans = max(ans, i - start + 1);
            map[s[i]] = i;
        }
        return ans;
    }
};
