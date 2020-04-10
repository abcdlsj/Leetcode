// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    vector<int> subSort(vector<int>& array) {
        if(array.size() == 0 || array.size() == 1) return {-1, -1};
        int MAX = INT_MIN, MIN = INT_MAX, right = -1, left = -1;
        //1,2,4, || 7,10,11,7,12,6,7, || 16,18,19
        for(int i = 0; i < array.size(); i++) {
            if(array[i] >= MAX) MAX = array[i];
            else right = i;
            if(array[array.size() - i - 1] <= MIN) MIN = array[array.size() - i - 1];
            else left = array.size() - i - 1;
        }
        return {left, right};
    }
};
