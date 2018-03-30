//
// Created by yutianpig on 18-3-30.
//
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string str;
        int maxlength=0;
        int x=(int)strs.size();
        if(x==1)
            return strs[0];
        if(x==0)
            return "";
        string x1=strs[0];
        string x2=strs[1];
        int d=0;
        while(x1[d]==x2[d])
            d++;
        str=x1.substr(0,d);
        maxlength=d;
        for(int i=2;i<x;i++)
        {
            string t=strs[i];
            int temp=0;
            while(str[temp]==t[temp])
                temp++;
            if(temp<maxlength)
            {
                maxlength=temp;
                str=t.substr(0,temp);
            }
        }
        return str;
    }
};
