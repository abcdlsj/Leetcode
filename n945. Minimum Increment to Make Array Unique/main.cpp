// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
        sort(A.begin(), A.end());
        int ans = 0;
        if(A.size() <= 1) return 0;
        for(int i = 1; i < A.size(); i++) {
            if(A[i-1] >= A[i]) {
                ans += A[i-1] - A[i] + 1;
                A[i] = A[i-1] + 1;
            }
        }
        return ans;
    }
};
