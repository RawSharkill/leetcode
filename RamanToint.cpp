//
// Created by yutianpig on 18-3-29.
//

//Ⅰ（1）、X（10）、C（100）、M（1000）、V（5）、L（50）、D（500）
//当符号 I、X 或 C 位于大数的后面时就作为加数；位于大数的前面就作为减数。

#include <iostream>
#include <string>
#include <map>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        map<char,int> m;//map(key,value)
        m.insert(make_pair('I',1));
        m.insert(make_pair('V',5));
        m.insert(make_pair('X',10));
        m.insert(make_pair('L',50));
        m.insert(make_pair('C',100));
        m.insert(make_pair('D',500));
        m.insert(make_pair('M',1000));

        int res = 0;
        for(int i=0; i<s.size(); )
        {
            if(m[s[i]] < m[s[i+1]])  // 左减
            {
                res += m[s[i+1]]-m[s[i]];
                i+=2;
            }
            else
            {
                res += m[s[i]];
                ++i;
            }
        }
        return res;
    }
};