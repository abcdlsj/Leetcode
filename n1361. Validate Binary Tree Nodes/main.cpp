// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    static const int N = 1e4+1;
    int father[N];
    
    int getfather(int x) {
        if(father[x]!=x) father[x] = getfather(father[x]);
        return father[x];
    }
    
    bool unionfa(int x, int y) {
        int px = getfather(x);
        int py = getfather(y);
        if (px == py) return false;
        if (px > py) swap(px,py);
        father[px] = py;
        return true;
    }
    
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        for(int i = 0; i < n; i++) {
            father[i] = i;
        }
        int cnt = n;
        
        for(int i = 0; i < n; i++) {
            if(leftChild[i] != -1) {
                if (unionfa(i , leftChild[i]) == false)
                    return false;
                -- cnt;     
            }
           if(rightChild[i] != -1) {
                if (unionfa(i , rightChild[i]) == false)
                    return false;
                -- cnt;     
            }
        }
        if (cnt != 1) return false;
        else return true;
    }
};
