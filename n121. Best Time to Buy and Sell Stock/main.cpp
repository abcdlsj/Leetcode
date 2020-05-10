// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() <= 1) return 0;
        int maxprofit = 0, minprices = prices[0];
        for(int i = 1; i < prices.size(); i++) {
            maxprofit = max(maxprofit, prices[i] - minprices);
            minprices = min(minprices, prices[i]);
        } 
        return maxprofit;
    }
};
