#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	int maxProduct(vector<int>& nums) {
		int x = nums.size();
		if ( nums.empty()||x == 0)
			return 0;
		else
		{
			vector<int> f(x);
			/*最开始我没有指定长度，结果就过不了，runtime error  
			现在加上长度就AC了*/
			vector<int> g(x);
			f[0] = nums[0];
			g[0] = nums[0];
			int maxp = nums[0];
			for (int i = 1; i < x; i++)
			{
				f[i] = max(max(f[i - 1] * nums[i], g[i - 1] * nums[i]), nums[i]);
				g[i] = min(min(f[i - 1] * nums[i], g[i - 1] * nums[i]), nums[i]);
				maxp = max(maxp, f[i]);
			}
			return maxp;
		}
	}
};
/*暴力法，真暴力，很显然不会过，但是还是写一下理解一下提议 嘤嘤嘤*/
/*class Solution {
public:
	int maxProduct(vector<int>& nums) {
		int x = nums.size();
		if (x == 1)
			return nums[0];
		else {
			vector<vector<int>> answer;
			int max = 0;
			for(int i=0;i<x;i++)
				for (int j = i; j < x; j++)
				{
					answer[i][j] = mul(i, j,nums);
					if (max < answer[i][j])
						max = answer[i][j];
				}
			return max;
		}
	}
	int mul(int i, int j, vector<int>nums) {
		int m=1;
		for (int k = i; k < j; k++)
			m = m * nums[k];
		return m;
	}
};*/