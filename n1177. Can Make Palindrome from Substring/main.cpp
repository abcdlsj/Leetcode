// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        int n=s.length();
        int cnt[n+1][26];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<26;j++)
                cnt[i+1][j]=cnt[i][j];
            cnt[i+1][s[i]-'a']++;
        }
        vector<bool> ans;
        for(auto q:queries)
        {
            int l=q[0],r=q[1]+1,k=q[2];
            int nk=0;
            for(int i=0;i<26;i++)
                if((cnt[r][i]-cnt[l][i])&1) nk++;
            ans.push_back((nk/2)<=k);
        }
        return ans;
    }
};
