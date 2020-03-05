// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    bool isUnique(string astr) {
        int sign = 0;
        for(int i = 0; i < astr.length(); i++) {
            int index = 1 << (astr[i] - 'a');
            if((index & sign) != 0) return false;
            else sign |= index;
        }
        return true;
    }
};
