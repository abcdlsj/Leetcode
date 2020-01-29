// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();if(n==0) return 0;
        if(n==1) return 0;
        if(n==2) return min(cost[0],cost[1]);
        vector<int> cnt(cost);
        cnt.push_back(0);
        for(int i=2;i<=n;i++)
            cnt[i] = min(cnt[i-1]+cnt[i],cnt[i-2]+cnt[i]);
        return min(cnt[n],cnt[n-1]);
    }
};
