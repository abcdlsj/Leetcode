// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

int count(int n) {
  int res = 0;
  while (n) {
    n = n & (n - 1);
    res++;
  }
  return res;
}
bool cmp(int a, int b) {
  if (count(a) == count(b)) {
    return a < b;
  } else
    return count(a) < count(b);
}
class Solution {
public:
  vector<int> sortByBits(vector<int> &arr) {
    sort(arr.begin(), arr.end(), cmp);
    return arr;
  }
};

