// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    string compressString(string S) {
        string res;
        int i = 0, j = 0;
        while(i < S.length() && j < S.length()) {
            while(S[i] == S[j]) j++;
            res += S[i];
            res += to_string(j - i);
            i = j;
        }
        return S.length() <= res.length() ? S : res;
        //return res;
    }
};
