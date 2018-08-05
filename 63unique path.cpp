//
// Created by yutianpig on 18-5-6.
//
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> >& obstacleGrid) {
        int x=(int)obstacleGrid.size();
        int y=(int)obstacleGrid[0].size();
        vector<vector<int> >answer(x,vector<int>(y));
        //初始第一行和第一列
       for(int k=0;k<x;k++)
       {
           if(obstacleGrid[k][0]==0)
               answer[k][0]=1;
           else
           {
               for(int o=k;o<x;o++)
                   answer[o][0]=0;
               break;
           }
       }
        for(int l=0;l<y;l++)
        {
            if(obstacleGrid[0][l]==0)
                answer[0][l]=1;
            else
            {
                for(int g=l;g<y;g++)
                    answer[0][g]=0;
                break;
            }
        }
        for(int i=1;i<x;i++)
        {
            for(int j=1;j<y;j++)
            {
                if(obstacleGrid[i][j]==0)
                {
                    answer[i][j]=answer[i][j-1]+answer[i-1][j];

                }
                if(obstacleGrid[i][j]==1)
                {
                    answer[i][j]=0;

                }
            }
        }
        return answer[x-1][y-1];
    }
};
int main()
{
    Solution s;
    vector<vector<int> >p={{0,0,0}, {0,1,0},{0,0,0}};
    cout<<s.uniquePathsWithObstacles(p);
}
