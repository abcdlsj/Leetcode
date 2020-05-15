// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // int fast = 0, slow = 0;
        // while(true) {
        //     fast = nums[nums[fast]];
        //     slow = nums[slow];
        //     if(fast == slow) break;
        // }
        // fast = 0;
        // while(fast != slow) {
        //     fast = nums[fast];
        //     slow = nums[slow];
        // }
        // return slow;
        int left = 1, right = nums.size() - 1, mid, cnt;
        while(left < right) {
            mid = left + (right - left) / 2, cnt = 0;
            for(auto num : nums) if(num <= mid) cnt++;
            if(cnt > mid) right = mid;
            else left = mid + 1;
        }
        return left;
    }
};
