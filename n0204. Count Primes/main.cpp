// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    int countPrimes(int n) {
        vector<bool> elds(n,true);
        int ans=0;
        for(int i=2;i<n;i++)
        {
            if(elds[i])
            {
                ans++;
                for(int j=2*i;j<n;j+=i)
                    elds[j]=false;
            }
        }
        return ans;
    }
};
