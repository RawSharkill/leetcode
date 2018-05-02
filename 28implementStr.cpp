//
// Created by yutianpig on 18-5-1.
//
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int lenh=haystack.size();
        int lenn=needle.size();
        if(lenn==0)
            return 0;
        int index=0;
        for(int j=0;j<lenh;j++)
          {
              if(haystack[j]==needle[0])
              {
                  index=j;
                  int m=j;
                  for(int i=0;i<lenn;i++)
                  {
                      if(haystack[m++]==needle[i])
                          continue;
                      else {
                          index=-1;
                          break;
                      }
                  }
                  if(index!=-1)
                      return index;
              }
          }
        return -1;
    }
};

int main()
{
    Solution s;
    cout<<s.strStr("hello","ll");
}