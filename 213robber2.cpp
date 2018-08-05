#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
class Solution {
public:
	int rob(vector<int>& nums) {
		int len = nums.size();
		if (len == 0)
			return 0;
		if (len == 1)
			return nums[0];
		if (len == 2)
			return max(nums[0], nums[1]);
		else
			return max(r(nums, 1, len-1), r(nums, 0, len - 2));
	}
	int r(vector<int>nums,int start,int end) {
		int n= end - start + 1;
		vector<int> d(n);
		d[0] = nums[start];
		d[1] = max(nums[start], nums[start + 1]);
		for (int i = 2; i<n; i++) {
			d[i] = max(d[i - 2] + nums[start + i], d[i - 1]);
		}
		return d[n - 1];
	}	
};