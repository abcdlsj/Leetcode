// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        vector<int> cnt;
        for (int a = 1;a < bound ; a *= x){
          for(int b = 1; a+b <= bound; b *= y)
          {
            cnt.push_back(a+b);
            if (y==1) break;
          }
          if(x==1) break; 
        }
        set<int> ans(cnt.begin(),cnt.end());
        cnt.assign(ans.begin(),ans.end());
        return cnt;
    }
};
