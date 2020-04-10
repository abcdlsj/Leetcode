// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    int abs(int x) {
        if(x < 0) return -x;
        return x;
    }
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int ans = arr1.size();
        if(d == 0) return ans;
        for(int i = 0; i < arr1.size(); i++) {
            for(int j = 0; j < arr2.size(); j++) {
                if(abs(arr1[i] - arr2[j]) <= d) {
                    ans--;
                    break;
                } 
            }
        }
        return ans;
    }
};
