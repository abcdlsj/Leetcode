// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    void reverseString(vector<char>& s) {
        int n = s.size();
        if(n == 1) return;
        for(int i = 0; i < n/2; i++) {
            s[i] = s[n-i-1]^s[i];
            s[n-i-1] = s[n-i-1]^s[i];
            s[i] = s[n-i-1]^s[i];
        }
        return;
    }
};
