// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.rbegin(), satisfaction.rend());
        int tmpsum = 0, sum = 0, ans = 0;
        for(int i = 0; i < satisfaction.size(); i++) {
            tmpsum += satisfaction[i];
            sum += tmpsum;
            ans = max(ans, sum);
        }
        return ans;
    }
};
