// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
    //     if(nums.size() == 1) return 0;
    //     int left = nums.size(), right = 0;
    //     for(int i = 0; i < nums.size() - 1; i++) {
    //         for(int j = i + 1; j < nums.size(); j++) {
    //             if(nums[j] < nums[i]){
    //                 left = min(left, i);
    //                 right = max(right, j);
    //             }
    //         }
    //     }
    //     return (right-left)<0?0:(right-left+1);
    // }
    // 超时
    // if(nums.size() == 1) return 0;
    // int left = nums.size() - 1, right = 0;
    // int leftmax = nums[0], rightmin = nums[left];
    // for(int i = 1; i < nums.size(); i++) {
    //     leftmax = max(leftmax, nums[i]);
    //     rightmin = min(rightmin, nums[nums.size() - i - 1]);
    //     if(nums[i] < leftmax) right = i;
    //     if(nums[nums.size() - i - 1] > rightmin) left = nums.size() - 1 - i;
    // }
    // return (right-left)<0?0:(right-left+1);
    if(nums.size() == 1) return 0;
    vector<int> cnt(nums);
    sort(nums.begin(), nums.end());
    int left = nums.size() - 1, right = 0;
    for(int i = 0; i < nums.size(); i++) {
        int k = nums.size()-i-1;
        if(nums[i] != cnt[i]) left = min(left, i);
        if(nums[k] != cnt[k]) right = max(right, k);
    }
    return (right-left)>0?(right-left+1):0;
    }
}; 
