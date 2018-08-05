//
// Created by yutianpig on 18-5-6.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int x=(int)grid.size();
        int y=(int)grid[0].size();
        vector<vector<int> >answer(x,vector<int>(y));
        //初始化第一行以及第一列
        answer[0][0]=grid[0][0];
        for(int k=1;k<x;k++)
        {
            answer[k][0]=answer[k-1][0]+grid[k][0];
        }
        for(int l=1;l<y;l++)
        {
            answer[0][l]=answer[0][l-1]+grid[0][l];
        }

        for(int i=1;i<x;i++)
        {
            for(int j=1;j<y;j++)
            {
                int term=answer[i-1][j]>answer[i][j-1]?answer[i][j-1]:answer[i-1][j];
                answer[i][j]=term+grid[i][j];
            }
        }
        return answer[x-1][y-1];
    }
};
int main()
{
    vector<vector<int> >p={{1,3,1},{1,5,1},{4,2,1}};
    Solution s;
    cout<<s.minPathSum(p);
}