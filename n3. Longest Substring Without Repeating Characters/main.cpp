// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0, right = 0, maxlen = 0;
        unordered_map<char, int> window;
        while(right < s.size()) {
            window[s[right]]++;
            while(window[s[right]] > 1) {
                window[s[left]]--;
                left++;
            }
            maxlen = max(maxlen, right - left + 1);
            right++;
        }
        return maxlen;
    }
};
