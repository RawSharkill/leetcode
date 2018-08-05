#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		int ans = 0, maxn = INT_MIN;
		int len = nums.size();
		for (int i = 0; i < len; i++) {
			if (ans < 0) ans = 0;  //���ǰ��ĺ�С0����ô���¿�ʼ���
			ans += nums[i];
			maxn = max(maxn, ans);
		}
		return maxn;
	}
};