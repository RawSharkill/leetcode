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
			��i�ĵط�ֻ�����ַ�������һ��̨�׻���������̨�ף���ô������i-1��һ��̨�ף�
			i-2������̨�ף����Խ��Ϊ������ӡ���
			*/
		}
		return dp[n];
	}
};