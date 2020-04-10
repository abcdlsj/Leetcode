// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
    if(nums.size() == 1) return 0;
    vector<int> cnt(nums);
    sort(nums.begin(), nums.end());
    int left = nums.size() - 1, right = 0;
    for(int i = 0; i < nums.size(); i++) {
        int k = nums.size() - i - 1;
        if(nums[i] != cnt[i]) left = min(left, i);
        if(nums[k] != cnt[k]) right = max(right, k);
    }
    return (right-left) > 0 ? (right-left+1) : 0;
    }
};
