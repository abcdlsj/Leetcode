// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    string w[7] = {"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};
    int a[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    int b[12] = {31,29,31,30,31,30,31,31,30,31,30,31};
    string dayOfTheWeek(int day, int month, int year) {
        int d=0;
        for(int i=1971;i<year;i++)
        {
            if((i%4==0&&i%100!=0)||i%400==0)
            {
                d+= 366;
            }
            else
                d+= 365;
        
        }
        if((year%4==0&&year%100!=0)||year%400==0)
        {
            for(int i=0;i<month-1;i++)
                d+=b[i];
            d +=day;
        }
        else
        {
            for(int i=0;i<month-1;i++)
                d+=a[i];
            d = d+day;  
        }
        return w[(d+4)%7];
    }
};
