// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    void reverseString(vector<char>& s) {
        if(s.size()==0) return;
        int n=s.size();
        int i=0,j=n-1;
        while(i<j){
            swap(s[i],s[j]);
            i++;
            j--;
        }
        return;
    }
};
