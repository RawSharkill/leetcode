#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
class Solution {
public:
	int coinChange(vector<int>& coins, int amount) {
		vector<int> dp(amount + 1);
		for (int k = 0; k < amount + 1; k++)
		{
			dp[k] = INT_MAX;
		}
		int x = coins.size();
		for (int l = 1; l < x; l++) {
			dp[coins[l]] = 1;
		}
		for (int i = 1; i < amount + 1; i++){
			int temp = find(coins, i);
			dp[i] = min(dp[i-temp]+dp[temp], dp[i]);
		}
	}
	int find(vector<int>& coins, int k) {
		for(int i=0;i<coins.size();i++)
			if (k < coins[i]) {
				return coins[i - 1];
			}
	}
};
*/
class Solution {
public:
	int coinChange(vector<int>& coins, int amount) {
		if (amount < 0) return -1;
		vector<int> cnt(amount + 1, amount + 1);
		cnt[0] = 0;
		for (int i = 1; i <= amount; ++i) {
			for (int j = 0; j<coins.size(); ++j) {
				if (i >= coins[j]) {
					cnt[i] = min(cnt[i], cnt[i - coins[j]] + 1);
				}
			}
		}
		return (cnt[amount] == amount + 1) ? -1 : cnt[amount];
	}
};