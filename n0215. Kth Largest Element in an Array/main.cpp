// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>> q;
        for(auto it:nums)
        {
            q.push(it);
            if(q.size()>k) q.pop();
        }
        return q.top();
    }
};
