// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    vector<vector<int>> largeGroupPositions(string S) {
        if(S.length()<3) return vector<vector<int>>();
        vector<vector<int>> ans;
        S+='A';
        int i=0,j=0,n=S.length();
        while(j<n)
        {
            if(S[j]==S[i])
                j++;
            else{
                if(j-i>=3)
                    ans.emplace_back(vector<int>{i,j-1});
                i=j;
            }
        }
        return ans;
    }
};
