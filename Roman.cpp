//
// Created by yutianpig on 18-3-29.
//
//Ⅰ（1）、X（10）、C（100）、M（1000）、V（5）、L（50）、D（500）
//当符号 I、X 或 C 位于大数的后面时就作为加数；位于大数的前面就作为减数。
#include <iostream>
#include <string>
using namespace std;
/*
class Solution {
public:
    string intToRoman(int num) {
        string str;
        int count=0;
        char roman[7]={'I','X','C','M','V','L','D'};
        while(num!=0){
            if(num>1000){
                int m=num/1000;
                for(int i=0;i<m;i++)
                str[count++]='M';
                num=num-m*1000;
            }
            if(num<1000&&num>100){
                int x=num/100;
                if(x==9)
                {
                    str[count]='C';
                    count++;
                    str[count]='M';
                }
                if(x>=5){
                    str[count]='D';
                    for(int i=0;i<x-5;i++)
                    {
                        count++;
                        str[count]='C';
                    }
                }
                if(x<5)
                {
                    if(x==4)
                    {
                        str[count]='C';
                        count++:
                        str[count]='D';
                    }
                    for(int i=0;i<x;i++)
                    {
                        str[count]='C';
                    }
                }
            }
            if(num<10)
        }
    }
};
 放弃掉自己的想法的原因是，千位，百位，十位，个位，都有类似的表示规则，所以每一个都会有很多种选择，用if 语句会很冗长。
 */
//Ⅰ（1）、X（10）、C（100）、M（1000）、V（5）、L（50）、D（500）
//当符号 I、X 或 C 位于大数的后面时就作为加数；位于大数的前面就作为减数。
class Solution {
    static const string THOUS[4];
    static const string HUNDS[10];
    static const string TENS[10];
    static const string ONES[10];
public:
    string intToRoman(int num) {
        string res;
        res += THOUS[num/1000];
        res += HUNDS[num/100%10];
        res += TENS[num/10%10];
        res += ONES[num%10];
        return res;
    }
};

const string Solution::THOUS[]  = {"","M","MM","MMM"};
const string Solution::HUNDS[]  = {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
const string Solution::TENS[]   = {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
const string Solution::ONES[]   = {"","I","II","III","IV","V","VI","VII","VIII","IX"};