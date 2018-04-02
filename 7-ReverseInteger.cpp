#include <string>
#include <iostream>
#include <math.h>
#include <climits>//INT_MAX
using namespace std;

class Solution {
public:
    int reverse(int x) {
        int answer=0;
        int s=abs(x);
        int d=s;
        int count=1;
        int count1=0;
        while(d!=0)
        {
            d=d/10;
            count1++;
        }
        count1--;
        while(s!=0)
        {
            answer+=s%10*pow(10,count1);
            s=s/10;
            count1--;
        }
        if(answer>INT_MAX/10||answer<INT_MIN/10)
            return 0;
        if(x>0)
            return answer;
        else
            return answer*(-1);
    }
};

int main()
{
    Solution s;;
    cout<<s.reverse(-130);
}
/*
 * class Solution {
public:
    int reverse(int x) {
        int res = 0;
        while(x!=0){
            if(res>INT_MAX/10||res<INT_MIN/10){
                return 0;
            }
            res = res*10 + x%10;
            x = x/10;
        }
        return res;
    }
};
 *
 */