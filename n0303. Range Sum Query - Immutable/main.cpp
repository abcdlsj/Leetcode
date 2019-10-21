// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class NumArray {
    vector<int> num;
public:
    NumArray(vector<int>& nums) {
        int s=0;
        num.push_back(s);
        for(int i=0;i<nums.size();++i){
            s+=nums[i];
            num.push_back(s);
        }
    }
    
    int sumRange(int i, int j) {
        return num[j+1]-num[i];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */
