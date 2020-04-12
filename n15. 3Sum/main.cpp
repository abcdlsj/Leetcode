// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> res;
        sort(nums.begin(), nums.end());
        for(int c = 0; c < nums.size() - 2 && nums.size() >= 3; c++) {
            int le = c + 1, ri = nums.size() - 1;
            while(le < ri) {
                if(nums[c] + nums[le] + nums[ri] == 0) {
                    res.insert({nums[c], nums[le], nums[ri]});
                    ri--;le++;
                    while(le < ri && nums[ri] == nums[ri+1]) ri--;
                    while(le < ri && nums[le] == nums[le-1]) le++;
                }
                else if(nums[c] + nums[le] + nums[ri] < 0)
                    le++;
                else 
                    ri--;
            }
        }
        vector<vector<int>> ans(res.begin(), res.end());
        return ans;
    }
};
