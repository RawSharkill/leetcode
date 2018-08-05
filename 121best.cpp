#include<iostream>
#include<vector>

using namespace std;
class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int x = prices.size();
		int best = 0;
		for (int i = 0; i < x; i++)
		{
			int sale = 0;
			for (int j = i; j < x; j++)
			{
				if (prices[j] > sale)
					sale = prices[j];
			}
			int p = sale - prices[i];
			if (p > best)
				best = p;
		}
		return best;
	}
};