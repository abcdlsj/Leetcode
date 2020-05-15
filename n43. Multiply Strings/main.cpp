// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1[0] == '0' || num2[0] == '0') return "0";
        int m = num1.size(), n = num2.size(), sum;
        vector<int> res(m + n, 0); string str;
        for(int i = num1.size() - 1; i >= 0; i--) {
            for(int j = num2.size() - 1; j >= 0; j--) {
                sum = res[i + j + 1] + (num1[i] - '0') * (num2[j] - '0');
                res[i + j + 1] = sum % 10;
                res[i + j] += sum / 10;
            }
        }
        for(int i = 0; i < res.size(); i++) {
            if(i == 0 && res[i] == 0) continue;
            str.push_back(res[i] + '0');
        }
        return str;
    }
};
