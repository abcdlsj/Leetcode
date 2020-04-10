// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if(flowerbed.empty()) return false;
        for(int i=0;i<flowerbed.size();i++)
        {
            if(flowerbed[i]==0&&(i-1==-1||flowerbed[i-1]==0)&&(i+1==flowerbed.size()||flowerbed[i+1]==0)) 
            {
                n--;
                flowerbed[i]=1;                
            }        
        }
        return n<=0?true:false;
    }
};
