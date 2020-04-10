// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    int smallestDifference(vector<int>& a, vector<int>& b) {
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        int i = 0, j = 0;
        long res = INT_MAX;
        while(i < a.size() && j < b.size()) {
            res = min(res, abs((long)a[i] - b[j]));
            if(a[i] <= b[j]) i++;
            else j++;
        }
        return res;
    } 
};
