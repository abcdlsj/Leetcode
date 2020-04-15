// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        int left = 1, right = 2, sum = left;
        vector<int> path;
        vector<vector<int>> res;
        while(right < target && left < right) {
            if(sum < target) {
                sum += right++;
            } else if(sum > target) {
                sum -= left++;
            } else {
                for(int i = left; i < right; i++) path.push_back(i);
                res.push_back(path);
                path.clear();
                sum -= left++;
            }
        }
        return res;
    }
};
