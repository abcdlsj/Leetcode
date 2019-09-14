// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    int countSegments(string s) {
        int n = s.size();
        int ans=0;
        if(n==0) return 0;
        for(int i=0;i<n-1;i++)
        {
            if(s[i]==' '&&s[i+1]!=' ')
                ans++;
        }
        return (s[0]==' ')?ans:ans+1;
    }
};
