// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        if(arr.size() == 0 || k == 0) return {};
        if(arr.size() == k) return arr;
        int n = arr.size(); vector<int> res;
        for(int index = (n - 1) / 2; index >= 0; index--) sink(arr, index, n);
        while(k--) {
            res.push_back(arr[0]);
            swap(arr[0], arr[--n]);
            sink(arr, 0, n);
        }
        return res;
    }
    void sink(vector<int> &arr, int index, int end) {
        int sIdx = index, left = index * 2 + 1, right = index * 2 + 2;

        if(left < end && arr[left] < arr[sIdx]) sIdx = left;
        if(right < end && arr[right] < arr[sIdx]) sIdx = right;

        if(sIdx != index) {
            swap(arr[sIdx], arr[index]);
            sink(arr, sIdx, end);
        }  
    }
};
