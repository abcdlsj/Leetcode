// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    bool isIsomorphic(string s, string t) {
      char *sc[128]={0};
      char *tc[128]={0};
      for(int i = 0;i<s.size();++i){
        sc[s[i]]+=i+1;
        tc[t[i]]+=i+1;
        if(sc[s[i]]!=tc[t[i]]) return false;
      }
      return true;
    }
};
