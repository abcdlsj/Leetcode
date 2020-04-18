// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> deque; vector<int> res;
        if(nums.size() == 0) return res;
        for(int i = 0; i < nums.size(); i++) {
            if(!deque.empty() && i - deque.front() + 1 > k) {
                deque.pop_front();
            }
            while(!deque.empty() && nums[i] > nums[deque.back()]) {
                deque.pop_back();
            }
            deque.push_back(i);
            if(i + 1 >= k) {
                res.push_back(nums[deque.front()]);
            }
        }
        return res;
    }
};
