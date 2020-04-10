// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    char firstUniqChar(string s) {
        map<char, int> map;
        for(auto ch : s) {
            map[ch]++;
        }
        for(auto ch : s) {
            if(map[ch] == 1) return ch;
        }
        return ' ';
    }
};
