//
// Created by yutianpig on 18-4-2.
//
#include <iostream>
#include <string>
#include <stack>
#include <queue>
using namespace std;
class Solution {
public:
    bool isValid(string s) {
        int i = 0;
        stack<char>sl;
       for(i=0;i<s.size();i++)
       {
           if(sl.empty())
               sl.push(s[i]);
           else if(sl.top()=='('&&s[i]==')' || sl.top()=='{'&&s[i]=='}' || sl.top()=='['&&s[i]==']')
               sl.pop();
           else
               sl.push(s[i]);
       }
        if(sl.empty())
            return true;
        else
            return false;
    }
};