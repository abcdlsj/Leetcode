// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0, sum = 0;
        unordered_map<int, int> map;

        map[0] = 1; 
        for (auto item : nums) {
            sum += item;
            if (map.find(sum - k) != map.end()) {
                count += map[sum - k];
            }
            if (map.find(sum) == map.end()) {
                map[sum] = 1;
            } else {
                map[sum]++;
            }
        }

        return count;
    }
};
