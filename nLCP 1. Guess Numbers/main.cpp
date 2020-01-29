// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    int game(vector<int>& guess, vector<int>& answer) {
        int ans=0;
        for(int i=0;i<3;++i){
            if(answer[i]==guess[i])
                ans++;
        }
        return ans;
    }
};
