// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    vector<int> constructArr(vector<int>& a) {
        vector<int> res(a.size(), 0);
        for(int i = 0, left = 1; i < a.size(); left *= a[i], i++) {
            res[i] = left;
        }
        for(int i = a.size() - 1, right = 1; i >= 0; right *= a[i], i--) {
            res[i] *= right;
        }
        return res;
    }
};
