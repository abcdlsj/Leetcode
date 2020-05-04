// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    vector<int> smallestK(vector<int>& arr, int k) {
        int n = arr.size(), end = n - 1;
        vector<int> res;
        for(int i = n / 2; i >= 0; i--) sink(arr, i, n - 1);
        while(k--) {
            res.push_back(arr[0]);
            swap(arr[0], arr[end--]);
            sink(arr, 0, end);
        }
        return res;
    }
    void sink(vector<int> &arr, int index, int end) {
        int sltIdx = index, left = index * 2 + 1, right = index * 2 + 2;

        if(left <= end && arr[left] < arr[sltIdx]) sltIdx = left;
        if(right <= end && arr[right] < arr[sltIdx]) sltIdx = right;

        if(sltIdx != index) {
            swap(arr[index], arr[sltIdx]);
            sink(arr, sltIdx, end);
        }
    }
};
