// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    bool isPalindrome(string s) {
        string str;
        for(auto c : s) {
            if(isalnum(c)) str += tolower(c);
        }
        for(int i = 0; i < str.size() / 2; i++) {
            if(str[i] != str[str.size() - i - 1]) return false;
        }
        return true;
    }
};
