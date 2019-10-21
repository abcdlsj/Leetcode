// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int n = J.size(),m=S.size(),ans=0;
        if(n==0||m==0) return 0;
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(J[i]==S[j])
                    ans++;
            }
        }
        return ans;
    }
};
