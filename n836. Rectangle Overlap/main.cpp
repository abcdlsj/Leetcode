// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        //四侧法
        return !(rec2[2]<=rec1[0] || 
                 rec2[0]>=rec1[2] ||
                 rec2[1]>=rec1[3] ||
                 rec2[3]<=rec1[1] );
        //IOU法
        return (min(rec2[2],rec1[2]) > max(rec2[0],rec1[0]) &&
               (min(rec2[3],rec1[3]) > max(rec2[1],rec1[1])));
    }
};
