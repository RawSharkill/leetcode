//
// Created by yutianpig on 18-3-25.
//
#include <iostream>

using namespace std;
class Solution {
public:
    string convert(string s, int numRows) {
        int x=(int)s.size();

        if(numRows==1 || x<=1)
            return s;

        int y=x/(2*numRows-2)*2+1;
        char d[numRows][y];
        for(int i=0;i<numRows;i++)
            for(int j=0;j<y;j++)
                d[i][j]=' ';
        int f=0;
        for(int i=0;i<y && f<x;i++)
        {
            if(i%2==0)
            {
                for(int j=0;j<numRows;j++)
                {
                    d[j][i]=s[f];
                    f++;
                }
            }
            else
            {
                for(int k=numRows-2;k>0;k--)
                {
                    d[k][i]=s[f];
                    f++;
                }

            }
        }
        string str;
        int j=0;
        int p=0;
        for(int i=0;i<numRows;i++)
        {
            for(int j=0;j<y;j++)
                if(d[i][j]!=' '&& p<=x)
                {
                    p++;
                    str.push_back(d[i][j]);
                }
        }
        return str;
    }
};
int main()
{
    Solution s;
    cout<<s.convert("abcde",3);
}
/*
 
class Solution
{
public:
    string convert(string s, int numRows)
    {
        int len=s.size();
        if(numRows==1||len<=numRows)
        {
            return s;
        }


        char ch[10000];
        int c=0;

        //1
        for(int i=0;i<len;)
        {
            ch[c++]=s[i];
            i+=(2*numRows-2);
        }
        //2
        for(int i=1;i<numRows-1;i++)
        {
            int j1=i;
            int j2=i+2*(numRows-i-1);
            while(j1<len||j2<len)
            {
                if(j1<len)
                {
                    ch[c++]=s[j1];
                    j1+=(2*numRows-2);
                }
                if(j2<len)
                {
                    ch[c++]=s[j2];
                    j2+=(2*numRows-2);
                }
            }
        }
        //3
        for(int i=numRows-1;i<len;)
        {
            ch[c++]=s[i];
            i+=(2*numRows-2);
        }

        return string(ch,ch+c);
    }
};
 */