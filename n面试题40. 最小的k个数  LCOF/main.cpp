// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
		int n = arr.size(); vector<int> res;
        if(n == 0 || k == 0 || k > n) return res;
        if(k == n) return arr;
        for(int i = (n - 1) / 2; i >= 0; i--) sink(arr, i, n);
        while(k--) {
            res.push_back(arr[0]);
            swap(arr[0], arr[n - 1]);
            sink(arr, 0, --n);
        }
        return res;
    }
    // 小顶堆
    void sink(vector<int> &arr, int index, int end) {
        int leastIdx = index, left = index * 2 + 1, right = index * 2 + 2;

        if(left < end && arr[leastIdx] > arr[left]) leastIdx = left;
        if(right < end && arr[leastIdx] > arr[right]) leastIdx = right;
        
        if(leastIdx != index) {
            swap(arr[leastIdx], arr[index]);
            sink(arr, leastIdx, end);
        }
    }
};
