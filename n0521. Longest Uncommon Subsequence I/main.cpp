// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

#include <cstring>
#include <cmath>
class Solution {
public:
    int findLUSlength(string a, string b) {
        if(a==b)
            return -1;
        else 
            return max(a.size(),b.size());
    }
};