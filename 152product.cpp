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
			/*�ʼ��û��ָ�����ȣ�����͹����ˣ�runtime error  
			���ڼ��ϳ��Ⱦ�AC��*/
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
/*���������汩��������Ȼ����������ǻ���дһ�����һ������ ������*/
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