// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    int numTeams(vector<int>& rating) {
        int ans = 0, n = rating.size();
        for (int i = 1; i < n - 1; i++) {
            int lless = 0, lmore = 0, rless = 0, rmore = 0;
            for (int j = 0; j < i; j++) {
                if (rating[j] < rating[i]) lless++;
                else if (rating[j] > rating[i]) lmore++;
            }

            for (int j = i + 1; j < n; j++) {
                if (rating[j] < rating[i]) rless++;
                else if (rating[j] > rating[i]) rmore++;
            }

            ans += lless * rmore + lmore * rless;
        }
        return ans;
    }
};
