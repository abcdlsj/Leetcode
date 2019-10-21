// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    int dietPlanPerformance(vector<int>& calories, int k, int lower, int upper) {
        int n=calories.size(),sum=0,ans;
        for(int i=0;i<n&&i+k<=n;i++)
        {
            ans=0;
            for(int j=0;j<k;j++)
                ans+=calories[i+j];
            if(ans<lower) sum -=1;
            if(ans>upper) sum +=1;
        }
        return sum;
    }
};
