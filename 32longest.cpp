#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
/*
最长公共子序列的做法类似，找next 的问题。
但是这个简单一些

*/
class Solution {
public:
	int longestValidParentheses(string s) {
		int result = 0;
		s = ')' + s;
		vector<int> dp(s.length(), 0);
		for (int i = 1; i<s.length(); i++)
		{
			if (s[i] == ')')
			{
				if (s[i - 1 - dp[i - 1]] == '(') dp[i] = dp[i - 1] + 2;
				dp[i] += dp[i - dp[i]];
			}
			result = max(result, dp[i]);
		}
		return result;
	}
};
