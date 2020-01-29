// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    int t[26];
    int f(string s)
    {
        memset(t,0,sizeof(t));
        for(char c:s)
            t[c-'a']++;
        for(int i=0;i<26;i++)
            if(t[i]) 
                return t[i];
        return 0;
    }
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        int n=queries.size(),m=words.size();
        vector <int> ans;
        vector <int> sum(15,0);
        for(string s:words)
            sum[f(s)]++;
        for(int i=10;i>=0;i--)
            sum[i]+=sum[i+1];
        for(string s:queries)
            ans.push_back(sum[f(s)+1]);
        return ans;
    }
};
