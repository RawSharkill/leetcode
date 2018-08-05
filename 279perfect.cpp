#include<iostream>
#include<algorithm>
#include<vector>
#include<limits>
using namespace std;

class Solution {
public:
	int numSquares(int n) {
		vector<int> dp(n + 1);
		for (int k = 0; k < n + 1; k++) {
			dp[k] = INT_MAX;
		}
		dp[1] = 1;
		for (int i = 1; i <= n; i++) {
			int s = sqrt(i);
			if (s*s == i)
				dp[i] = 1;
			else {
				for (int j = 1; j <= i / 2; j++) {
					dp[i] = min(dp[j] + dp[i - j], dp[i]);
				}
			}
		}
		return dp[n];
	}
};