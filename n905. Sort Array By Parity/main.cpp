// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

/*
双指针
*/
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        int n = A.size();
        int i = 0, j = n - 1;
        while(i <= j) {
            if(A[i] % 2 == 1 && A[j] % 2 == 0)
                swap(A[i],A[j]);
            if(A[i]%2 == 0) ++i;
            if(A[j]%2 == 1) --j;
        }
        return A;
    }
};
