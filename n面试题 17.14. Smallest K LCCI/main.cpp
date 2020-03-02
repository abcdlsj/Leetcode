// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    // int quicksort(vector<int> &arr, int begin, int end) {
        // int cpr = arr[end];
        // int left = begin, right = end - 1;
        // while(left < right) {
            // while(left < right && arr[left] < cpr) left ++;
            // while(left < right && arr[right] >= cpr) right --;
            // swap(arr[left],arr[right]);
        // }
        // swap(arr[left],arr[end]);
        // return left; 
    // }
    int partition(vector<int> &arr, int begin, int end) {
        int cpr = arr[end];
        int left = begin - 1, right = begin;
        for(; right < end; ++right) {
            if(arr[right] <= cpr) {
                ++ left;
                swap(arr[left], arr[right]);
            }
        }
        swap(arr[left+1], arr[end]);
        return left+1; 
    }
    void quick_sort(vector<int> &arr,int left,int right,int k) {
        if(left < right && left < k){
            int p = partition(arr, left, right);
            quick_sort(arr, left, p-1, k);
            if(p < k)
            {
                quick_sort(arr, p+1, right, k);
            }   
        }
    }
    vector<int> smallestK(vector<int>& arr, int k) {
        vector<int> res;
        if(k == 0) return res;
        if(arr.size() == k) return arr;
        quick_sort(arr, 0, arr.size() - 1, k);
        for(int i = 0; i < k; i++) {
            res.push_back(arr[i]);
        }
        return res;
    }
};
