// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    int strToInt(string str) {
        int ans = 0, start = 0;
        bool flag = true;
        while(start < str.size() && str[start] == ' ') start++;
        if(str[start] == '+' || str[start] == '-') {
            flag = str[start] == '-' ? false : true;
            start = start + 1;
        }
        while(start < str.size() && str[start] - '0' >= 0 && str[start] - '0' <= 9) {
            int cur = str[start] - '0';
            if(flag == true && (ans > INT_MAX / 10 || (ans == INT_MAX / 10 && cur >= 7))) return INT_MAX;
            if(flag == false && (-ans < INT_MIN / 10 || (-ans == INT_MIN / 10 && cur >= 8))) return INT_MIN;
            ans = ans * 10 + cur;
            start++;
        }
        return flag ? ans : -ans;
    }
};
