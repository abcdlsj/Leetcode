// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

/*
 * @lc app=leetcode.cn id=69 lang=cpp
 *
 * [69] x 的平方根
 */
class Solution {
public:
    int mySqrt(int x)
    {
        if(x==0) return 0;
        long res=x;
        while(res*res>x)
            res=(res+x/res)/2;
        return (int)res; 
    }
};


