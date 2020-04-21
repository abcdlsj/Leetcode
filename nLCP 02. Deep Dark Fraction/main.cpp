// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    vector<int> fraction(vector<int>& cont) {
        vector<int> ans;
        int t=cont.size()-1;
        int n=0,m=1;
        for(int i=t;i>0;--i){
            n=n+cont[i]*m;
            swap(n,m);
        }
        n = cont[0]*m+n;
        ans.push_back(n);
        ans.push_back(m);
        return ans;
        
    }
};
