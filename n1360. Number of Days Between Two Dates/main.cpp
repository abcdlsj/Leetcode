// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    bool runyear(int year){
        return ((year%4==0&&year%100!=0)||year%400==0);
    }
    int getdays(string s){
        int monthes[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
        int year = 0,month = 0,day = 0;
        for(int i = 0; i < 4; i++)
            year = year*10+(s[i] - '0');
        month = 10*(int)(s[5] - '0')+ (int)(s[6] - '0');
        day = 10*(int)(s[8] - '0')+ (int)(s[9] - '0');
        if(runyear(year))
            monthes[1] = 29;
        for(int i = 0; i < month - 1; i++)
            day += monthes[i];
        for(int i = 1971; i < year; i++)
            day += runyear(i)?366:365;
        return day;
    }
    int daysBetweenDates(string date1, string date2) {
        return fabs(getdays(date1)-getdays(date2));
    }
};
