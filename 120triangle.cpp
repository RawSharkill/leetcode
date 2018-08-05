#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
�������ϼ��㣬���������������⣬���Ҳ�����δ֪�⡣
��̬�滮�Ǹ��÷�����
*/
class Solution {
public:
	int minimumTotal(vector<vector<int>>& triangle)
	{
		int length = triangle.size();
		if (length == 0)return 0;
		if (length == 1)return triangle[0][0];
		vector<int>temp(triangle.size(), 0);
		vector<vector<int>> MP(length, temp);
		MP[length - 1] = triangle[length - 1];//�����εײ�һ���κ�һ��λ�ôﵽ�ײ����·��Ϊ�䱾��

		for (int i = length - 2; i >= 0; i--)
		{
			for (int j = 0; j<triangle[i].size(); j++)
			{
				MP[i][j] = min(MP[i + 1][j], MP[i + 1][j + 1]) + triangle[i][j];
			}
		}
		return MP[0][0];
	}
};