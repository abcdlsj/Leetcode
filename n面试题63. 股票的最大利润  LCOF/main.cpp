// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() <= 1) return 0;
        int minprice = prices[0], maxprofit = 0;
        
        for(int i = 1; i < prices.size(); i++) {
            maxprofit = max(maxprofit, prices[i] - minprice);
            minprice = min(minprice, prices[i]);
        }

        return maxprofit;
    }
};
