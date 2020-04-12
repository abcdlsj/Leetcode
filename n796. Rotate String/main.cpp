// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    bool rotateString(string A, string B) {
        return A.length() == B.length() && (A + A).find(B) != -1;
    }
};
