// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() <= 1) return 0;

        int minprices = prices[0], maxprofit = 0;
        // i 天的最大获利 = max(前 i-1 天的最大获利，i 天的价格 - 前 i-1 天的最小价格)；
        for(int i = 1; i < prices.size(); i++) {
            maxprofit = max(maxprofit, prices[i] - minprices);
            minprices = min(minprices, prices[i]); 
        }
        return maxprofit;
    }
};
