#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class NumArray {
public:
	vector<int> n;
	NumArray(vector<int> nums) {
		if (nums.empty())
			return;
		n.push_back(0);
		for (int o = 1; o <= nums.size(); o++) {
			n.push_back(nums[o-1]+n[o-1]);
		}
	}

	int sumRange(int i, int j) {
		return n[j + 1] - n[i];
	}
};

/**
* Your NumArray object will be instantiated and called as such:
* NumArray obj = new NumArray(nums);
* int param_1 = obj.sumRange(i,j);
*/