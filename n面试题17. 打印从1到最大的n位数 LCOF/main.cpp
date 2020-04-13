// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    vector<int> printNumbers(int n) {
        int num = 0;
        for(int i = 0; i < n; i++) {
            num = num * 10;
            num += 9;
        }
        vector<int> res;
        for(int i = 1; i <= num; i++) {
            res.push_back(i);
        }
        return res;
    }
};
