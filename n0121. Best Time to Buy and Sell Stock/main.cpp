// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sum=0,ans=0;
        for(int i =0;i<(int)prices.size()-1;++i){
            sum = max(0,sum+prices[i+1]-prices[i]);
            ans = max(ans,sum);
        }
        return ans;
    }
};
