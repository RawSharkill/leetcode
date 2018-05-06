//
// Created by yutianpig on 18-5-6.
//
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
/*
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m=word1.length();
        int n=word2.length();
        vector<vector<int> > distance(m+1,vector<int>(n+1));

        for(int i=0;i<=m;i++){
            for(int j=0;j<=n;j++){
                if(0==i){
                    distance[i][j]=j;
                }
                else if(0==j){
                    distance[i][j]=i;
                }
                else{
                    distance[i][j]=min(distance[i-1][j-1]+((word1[i-1]==word2[j-1])?0:1),
                                       min(distance[i-1][j]+1,distance[i][j-1]+1)
                                       );
                }
            }
        }
        return distance[m][n];
    }
};
 */

class Solution {
public:
    int minDistance(string word1, string word2) {
        int n=(int)word1.size();
        int m=(int)word2.size();
        int answer[m+1][n+1];
        if(n==0)
            return m;
        for(int k=0;k<=n;k++)
        {
            answer[0][k]=k;
        }
        for(int l=0;l<=m;l++)
        {
            answer[l][0]=l;
        }

        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                int term=min(answer[i-1][j],answer[i][j-1]);
                if(word1[i-1]==word2[j-1])
                {
                    answer[i][j]=answer[i-1][j-1];
                }
                else
                    answer[i][j]=min(term+1,answer[i-1][j-1]+1);
            }
        }
        return answer[m][n];
    }
};
int main()
{
    Solution s;
    cout<<s.minDistance("mart","karma");
}