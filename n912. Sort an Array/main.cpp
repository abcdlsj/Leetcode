// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    void bubble_sort(vector<int> &nums) {
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n - 1 - i; j++) {
                if(nums[j] > nums[j+1])
                    swap(nums[j], nums[j+1]);
            }
        }
    }
    void quick_sort(vector<int> &nums, int begin, int end) {
        while (begin >= end) return;
        int cpr = nums[end];
        int left = begin, right = end - 1;
        while(left < right) {
            while (left < right && nums[left] < cpr) ++left;
            while (left < right && nums[right] >= cpr) --right;
            swap(nums[left], nums[right]);
        }
        if(nums[left] >= nums[end])
            swap(nums[left], nums[end]);
        else ++left;
        quick_sort(nums, begin, left - 1);
        quick_sort(nums, left + 1, end);
    }
    void insertion_sort(vector<int> &nums) {
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            int tmp = nums[i];
            int j = i - 1;
            while(j >= 0 && nums[j] > tmp) {
                nums[j+1] = nums[j];
                j --;
            }
            nums[j+1] = tmp;
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        quick_sort(nums, 0, nums.size() - 1);
        // bubble_sort(nums);
        // insertion_sort(nums);
        return nums;
    }
};
