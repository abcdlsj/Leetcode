// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        vector<int> cnt(arr);
        vector<vector<int>> ans;
        for(int i=0;i<arr.size()-1;++i){
            cnt[i] = arr[i+1]-arr[i];
        }
        int min=cnt[0];
        for(int i=0;i<arr.size()-1;++i)
            if(min>cnt[i]) min=cnt[i];

        for(int i=0;i<arr.size()-1;++i){
            if(cnt[i]==min) {
                vector<int> bns;
                bns.push_back(arr[i]);
                bns.push_back(arr[i+1]);
                ans.push_back(bns);
            }
        }
        return ans;
    }
};
