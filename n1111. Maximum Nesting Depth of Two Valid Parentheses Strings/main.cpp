// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        vector<int> res(seq.length());
        int fora = 1;
        for(int i = 0; i < seq.length(); i++) {
            if(seq[i] == '(') {
                fora ^= 1;
                res[i] = fora;
            } else {
                res[i] = fora;
                fora ^= 1;
            }
        }
        return res;
    }
};
