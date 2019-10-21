// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        bool flag=true;
        int i=0,j=0;
        while(i<name.size())
        {
            if(name[i]==typed[j])
                i++,j++;
            else
            {
                if(typed[j]!=typed[j-1])
                {
                    flag=false;
                    break;
                }
                j++;
            }
        }
        return flag;
    }
};
