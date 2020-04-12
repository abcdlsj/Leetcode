// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.length(), m = needle.length();
        if((n == 0 && m != 0)) return -1;
        if((m == 0 && n == 0) || (n != 0 && m == 0)) return 0;
        for(int i = 0; i < n - m + 1; i++) {
            if(haystack[i] != needle[0]) continue;
            int flag = 1;
            for(int j = 0; j < m; j++) {
                if(haystack[i + j] != needle[j]) {
                    flag = 0;
                    break;
                }
            }
            if(flag == 1) return i;
        }
        return -1;
    }
};
