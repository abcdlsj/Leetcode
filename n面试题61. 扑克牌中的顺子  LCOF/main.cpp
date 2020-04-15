// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    bool isStraight(vector<int>& nums) {
        int cnt = 0, maxnum = INT_MIN, minnum = INT_MAX;
        set<int> set;
        for(auto num : nums) {
            if(num == 0) {
                cnt++;
            } else {
                if(set.find(num) == set.end()) {
                    maxnum = max(maxnum, num);
                    minnum = min(minnum, num);
                    set.insert(num);  
                } else {
                    return false;
                }
            }
        }
        if(cnt == 0) {
            return (maxnum - minnum) == 4;
        } else {
            return (maxnum - minnum) <= 4;
        }
    }
};
