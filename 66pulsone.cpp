#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	vector<int> plusOne(vector<int>& digits) {
		int c = 1;//初始化进位标志
		for (int i = digits.size() - 1; i >= 0; --i)
		{
			int a = digits[i] + c;
			digits[i] = a % 10;
			c = a / 10;
		}
		if (c == 1)
			digits.insert(digits.begin(), 1);
		return digits;
	}
};