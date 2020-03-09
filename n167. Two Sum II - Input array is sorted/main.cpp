// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> cpr(numbers.size());
        vector<int> res;
        if(numbers.size() == 0) return res;
        for(int i = 0; i < numbers.size(); ++i) {
            cpr[i] = target - numbers[i];
        }
        int i = 0, j = numbers.size() - 1;
        while(i < j) {
            if(numbers[i] == cpr[j]) {
                res.push_back(i+1);
                res.push_back(j+1);
                return res;
            }
            else if(cpr[j] < numbers[i]) -- j;
            else ++ i;
       }
       return res;
    }
};
