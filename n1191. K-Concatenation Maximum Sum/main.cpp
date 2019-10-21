// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    typedef long long LL;
    LL MO = 1e9+7;
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        LL sum = 0,ans=0;
        for(auto n:arr) sum+=n;
        LL lmx=0,rmx=0,nmx=0,nnmx=0;
        //nnmx 是单数组最大子数组 lmx 是左最大 rmx 右最大 nmx 是过程量；
        for(int i=0;i<arr.size();i++){
            nmx=max(nmx+arr[i],(LL)arr[i]);
            nnmx=max(nnmx,nmx);
        }
        nmx=0;
        for(int i=0;i<arr.size();++i){
            nmx+=arr[i];
            lmx=max(lmx,nmx);
        }
        nmx=0;
        for(int i=arr.size()-1;i>=0;--i){
            nmx+=arr[i];
            rmx=max(rmx,nmx);
        }
        if(k==1) return nnmx%MO;
        else {
            ans = max(nnmx,max(lmx+rmx,lmx+rmx+(k-2)*sum));
            return ans%MO;
        }
        
        return ans%MO;
    }
};
