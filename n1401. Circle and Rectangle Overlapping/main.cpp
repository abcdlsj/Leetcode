// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    bool checkOverlap(int radius, int x_center, int y_center, int x1, int y1, int x2, int y2) {
        double rectCenterX = (x2 + x1) / 2.0;
        double rectCenterY = (y2 + y1) / 2.0;

        vector<double> circleCenter2rectCenter = {abs(x_center - rectCenterX), abs(y_center - rectCenterY)};
        vector<double> vertex2rectCenter = {x2 - rectCenterX, y2 - rectCenterY};

        double vecX = max(circleCenter2rectCenter[0] - vertex2rectCenter[0], 0.0);
        double vecY = max(circleCenter2rectCenter[1] - vertex2rectCenter[1], 0.0);

        return sqrt(vecX * vecX + vecY * vecY) <= radius;
    }
};
