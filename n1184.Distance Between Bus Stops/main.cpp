// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        int n = distance.size(),a=0,b=0;
        if(start==destination) return 0;
        if(start<destination){
            for(int i=start;i<destination;i++)
                a+=distance[i];
        }
        if(start>destination)
            for(int i=start-1;i>=destination;i--)
                a+=distance[i];
        for(int i=0;i<n;i++)
            b+=distance[i];
        if(2*a<=b)
            return a;
        else return b-a;
    }
};
