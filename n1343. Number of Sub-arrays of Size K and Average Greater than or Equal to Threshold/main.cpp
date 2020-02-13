// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
      //滑动窗口，昨天没想到，导致时间复杂度爆了
      int n = arr.size(),sum = 0,ans = 0;
      threshold *= k;
      if(k > n) return 0;
      for(int i = 0; i < k; i++){
        sum += arr[i];
      }
      if(sum >= threshold) ans++;
      for(int i = k; i < n; i++){
        sum = sum - arr[i - k] + arr[i];
        if(sum >= threshold) ans++;
      }
      return ans;
    }
};
