// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    string largestTimeFromDigits(vector<int>& A) {
		int res = -1;
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++)if (j != i)
				for (int k = 0; k < 4; k++)if (k != i && k != j) {
					int l = 6 - i - j - k;
					int hours = 10 * A[i] + A[j];
					int mins = 10 * A[k] + A[l];
					if (hours < 24 && mins < 60)
						res = max(res, hours * 60 + mins);
				}
		if (res >= 0) {
			char c[6];
			sprintf(c, "%.2d:%.2d", res / 60, res % 60);
			return c;
		}
		return "";
    }
};
