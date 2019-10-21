// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size()==0||matrix[0].size()==0) return 0;
        int i=0,j=matrix[0].size()-1,cnt=0;
        while(i<matrix.size()&&j>=0)
        {
            cnt=matrix[i][j];
            if(cnt==target) return true;
            else if(cnt<target) i++;
            else j--;
        }
        return false;
    }
};
