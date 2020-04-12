// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        queue<string> path;
        unordered_set<string> vis, deads(deadends.begin(), deadends.end());
        vis.insert("0000"); path.push("0000");
        if(deads.count(path.front())) return -1;
        int cnt = 0; vector<int> dir = {-1,1};
        while(!path.empty()) {
            int size = path.size();
            while(size--) {
                string cur = path.front(); path.pop();
                if(cur == target) return cnt;
                for(int i = 0; i < 4; i++) {
                    for(int j = 0; j < 2; j++) {
                        string tes = cur;
                        tes[i] = '0' + (tes[i]-'0'+10+dir[j])%10;
                        if(vis.count(tes) || deads.count(tes)) continue;
                        path.push(tes);
                        vis.insert(tes);
                    }
                }
            }
            cnt ++;
        }
        return -1;
    }
};
