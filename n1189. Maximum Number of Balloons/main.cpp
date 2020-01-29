// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    int cnt[30];
    int maxNumberOfBalloons(string text) {
        memset(cnt,0,sizeof(cnt));
        for(auto c : text) ++cnt[c-'a'];
        
        return min(min(min(cnt['b'-'a'],cnt['a'-'a']),min(cnt['l'-'a']/2,cnt['o'-'a']/2)),cnt['n'-'a']);
    }
};
