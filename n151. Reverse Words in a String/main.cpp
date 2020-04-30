// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        int cur = 0;
        for(int left = 0; left < s.size(); left++) {
            if(s[left] != ' ') {
                if(cur != 0) {
                    s[cur++] = ' ';
                }
            }
            int right = left;
            while(s[right] != ' ' && right < s.size()) {
                s[cur++] = s[right++];
            }
            reverse(s.begin() + cur - (right - left), s.begin() + cur);
            left = right;
        }
        s.erase(s.begin() + cur, s.end());
        return s;
    }
};
