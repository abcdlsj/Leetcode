// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    int hammingDistance(int x, int y) {
        bitset <32> bin(x^y);
        return bin.count();
    }
};
