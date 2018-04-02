#include <climits>
#include <iostream>
using namespace std;
class Solution {
public:
    int myAtoi(string str) {
        long res = 0;//这里不能是int类型
        int indicator = 1;//这里要有默认值为1
        int i = str.find_first_not_of(' ');
        if(str[i] == '-' || str[i] == '+'){//以第一次出现的正负号为准
            indicator = (str[i++] == '-')?-1:1;
        }
        while(str[i]>='0' && str[i] <= '9'){
            res = res *10 + (str[i++]-'0');
            if(res*indicator >= INT_MAX) return INT_MAX;
            if(res*indicator <= INT_MIN) return INT_MIN ;
        }
        return indicator*res;
    }

};