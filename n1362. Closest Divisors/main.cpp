// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    vector<vector<int>> divisors(int num){
        vector<vector<int>> cnt;
        vector<int> tmp(2,0);
        for(int i = 1; i <= floor(sqrt(num)); ++i) {
            if(num%i==0) {
                tmp[0] = i;
                tmp[1] = num / i;
            }
                cnt.push_back(tmp);
        }
        return cnt;
    }
    vector<int> closestDivisors(int num) {
        vector<vector<int>> num1 = divisors(num+1);
        vector<vector<int>> num2 = divisors(num+2);
        int flag = 0;
        vector<int> ret;
        if((num1[num1.size()-1][1]-num1[num1.size()-1][0])>=(num2[num2.size()-1][1]-num2[num2.size()-1][0]))
        {
            ret.push_back(num2[num2.size()-1][1]);
            ret.push_back(num2[num2.size()-1][0]);
        }
        else{
            ret.push_back(num1[num1.size()-1][1]);
            ret.push_back(num1[num1.size()-1][0]); 
        }
 
        return ret;
    }   
};
