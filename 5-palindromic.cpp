#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.size() <= 1){
            return s;
        }

        int begin = 0;
        int maxLen = 1;
        for (int i=0; i<s.size() && (s.size()-i)*2>= maxLen;){
            int left=i, right = i;
            //跳过重复的元素
            while (right < s.size()-1 && s[right] == s[right+1]){ right ++; }
            i = right+1; //右边非重复的第一个
            while (left>0 && right<s.size() && s[left-1]==s[right+1]){
                left --;
                right ++;
            }
            if (maxLen<(right-left+1)){
                maxLen = right-left+1;
                begin = left;
            }
        }

        return s.substr(begin, maxLen);

    }
};

int main()
{
    Solution s;
    s.longestPalindrome("bbabb");
}