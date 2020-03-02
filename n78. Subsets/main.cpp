// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        
        vector<vector<int>> res;
        vector<int> cnt;

        int m = 0;

        while(m < (1 << n)){
            for(int i = 0; i < n; ++i){
                if((1 << i) & m) cnt.push_back(nums[i]);
            }
            res.push_back(cnt);
            cnt.clear();
            m ++;
        }
        return res;
    }
};
