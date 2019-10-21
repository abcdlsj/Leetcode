// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        R0:
        for(vector<int>::iterator i=nums.begin();i!=nums.end()-1;i++){
            for(vector<int>::iterator j=i+1;j!=nums.end();j++){
                if(*i==*j){
                    nums.erase(j);
                    nums.erase(i);
                    goto R0;
                }
            }
        }
        return nums;
    }
};
