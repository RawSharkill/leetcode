//
// Created by yutianpig on 18-5-1.
//
#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;
//官网实际答案
//官网答案，我的微改版
class Solution {
public:
    int divide(int dividend, int divisor) {
        long long a=abs(dividend); //(long long) dividend中的(long long)是为了防止-2147483648带来的溢出，下行同理。
        long long b=abs(divisor);
        int res=0;
        while(a>=b){
            long long c=b;
            for(int i=0;c<=a;i++){
                a-=c;
                res+=1<<i;
                c=c<<1;
            }
        }
        return ((dividend^divisor)>>31) ? (int)(-res) : (int)(res);//判断是否为负数
    }
};

int main()
{
    Solution s;
    cout<<s.divide(-2147483648,-1);
}