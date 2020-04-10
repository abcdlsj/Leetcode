// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    static int nums(int x) {
        int cnt = 0;
        while(x != 1) {
            if(x % 2 == 0) x /= 2;
            else x = x*3 + 1;
            cnt ++;
        }
        return cnt;
    }
    static bool cpr(int i, int j) {
        if(i == j) return i <= j ? true:false;
        else if(nums(i) == nums(j)) return i <= j ? true:false;
        else {
            return nums(i) < nums(j) ? true:false;
        }
    }
    int getKth(int lo, int hi, int k) {
        vector<int> cnt;
        for(int i = lo; i <= hi; i++) cnt.push_back(i);
        sort(cnt.begin(), cnt.end(), cpr);
        for(int i = 0; i < cnt.size(); i++) cout << cnt[i] << " ";
        for(int i = 0; i < k; i++) {
            while(i == k - 1) return cnt[i];
        }
        return 0;
    }
};
