// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    const long long mod=1e9+7;
    long long get(int n)
    {
        long long sum=1;
        for(int i=2;i<=n;i++)
            sum=i*sum%mod;
        return sum;
    }
    int getprime(int n)
    {
        vector<bool> elds(n+1,true);
        int ans=0;
        for(int i=2;i<=n;i++)
        {
            if(elds[i])
            {
                ans++;
                for(int j=2*i;j<=n;j+=i)
                    elds[j]=false;
            }
        }
        return ans;
    }
    int numPrimeArrangements(int n) {
        int ans = getprime(n);
        return get(ans)*get(n-ans)%mod;
    }
};
