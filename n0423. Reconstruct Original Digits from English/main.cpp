// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    string originalDigits(string s) {
        string result = "";
        vector<int> chCnt(128, 0);
        //统计各个字符出现的次数
        for (auto ch : s){
            chCnt[ch] += 1;
        }
        //zero one two three four five six seven eight nine
        //zero特征字母'z'
        if (chCnt['z'] > 0){
            result += string(chCnt['z'], '0');
        }
        //one特征字母'o'，减去zero中的'z',two中的'w',four中的'u'
        if (chCnt['o'] - chCnt['z'] - chCnt['w'] - chCnt['u'] > 0){
            result += string(chCnt['o'] - chCnt['z'] - chCnt['w'] - chCnt['u'], '1');
        }
        //two特征字母'w'
        if (chCnt['w'] > 0){
            result += string(chCnt['w'], '2');
        }
        //three特征字母'r'，减去zero中的'z'，four中的'u'
        if (chCnt['r'] - chCnt['z'] - chCnt['u'] > 0){
            result += string(chCnt['r'] - chCnt['z'] - chCnt['u'], '3');
        }
        //four特征字母'u'
        if (chCnt['u'] > 0){
            result += string(chCnt['u'] , '4');
        }
        //five特征字母'f'，减去four中的'u'
        if (chCnt['f'] - chCnt['u'] > 0){
            result += string(chCnt['f'] - chCnt['u'], '5');
        }
        //six特征字母'x'
        if (chCnt['x'] > 0){
            result += string(chCnt['x'], '6');
        }
        //seven特征字母's',减去six中的'x'
        if (chCnt['s'] - chCnt['x']> 0){
            result += string(chCnt['s'] - chCnt['x'], '7');
        }
        //eight特征字母'g'
        if (chCnt['g'] > 0){
            result += string(chCnt['g'], '8');
        }
        //nine特征字母'i'，减去five中的f(chCnt['f'] - chCnt['u']),six中的'x',eight中的g
        if (chCnt['i'] - (chCnt['f'] - chCnt['u']) - chCnt['x'] - chCnt['g'] > 0){
            result += string(chCnt['i'] - (chCnt['f'] - chCnt['u']) - chCnt['x'] - chCnt['g'], '9');
        }
        return result;
    }
};
