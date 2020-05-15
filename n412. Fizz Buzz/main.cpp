// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> res(n, "");
        for(int i = 0; i < n; i++) {
            if((i + 1) % 3 == 0) {
                res[i] += "Fizz";
            }
            if((i + 1) % 5 == 0) {
                res[i] += "Buzz";
            } 
            if((i + 1) % 3 != 0 && (i + 1) % 5 != 0){
                res[i] += to_string(i + 1);
            } 
        }
        return res;
    }
};
