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
    //归并
    void merge(vector<int> &Array, int front, int mid, int end) {
        vector<int> LeftSubArray(Array.begin() + front, Array.begin() + mid + 1);
        vector<int> RightSubArray(Array.begin() + mid + 1, Array.begin() + end + 1);

        int idxLeft = 0, idxRight = 0;
        LeftSubArray.insert(LeftSubArray.end(), numeric_limits<int>::max());
        RightSubArray.insert(RightSubArray.end(), numeric_limits<int>::max());

        for(int i = front; i <= end; i++){
            if(LeftSubArray[idxLeft] < RightSubArray[idxRight]) {
                Array[i] = LeftSubArray[idxLeft];
                idxLeft ++; 
            } else {
                Array[i] = RightSubArray[idxRight];
                idxRight ++;
            }
        }
    }

    void MergeSort(vector<int> &Array, int front, int end) {
        if(front >= end) return;
        int mid = front + (end - front) / 2;
        MergeSort(Array, front, mid);
        MergeSort(Array, mid + 1, end);
        merge(Array, front, mid, end); 
    }


    vector<int> sortArray(vector<int>& nums) {
        // quick_sort(nums, 0, nums.size() - 1);
        // bubble_sort(nums);
        // insertion_sort(nums);
        MergeSort(nums, 0, nums.size() - 1);
        return nums;
    }
};
