#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	int climbStairs(int n) {
		vector<int> dp(n+2);
		if (n < 1)
			return 0;
		dp[0] = 0;
		dp[1] = 1;
		dp[2] = 2;
		for (int i = 3; i <= n; i++) {
			dp[i] = dp[i - 1] + dp[i - 2];
			/*
			到i的地方只有两种方法，走一个台阶或者走两个台阶，那么就是在i-1走一个台阶，
			i-2走两个台阶，所以结果为两个相加、。
			*/
		}
		return dp[n];
	}
};