//
// Created by yutianpig on 18-4-4.
//
#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        string s="";
        vector<string> answer;
        for(int i=0;i<n;i++){
            s+="()";
        }
        answer.push_back(s);
        for(int j=0;j<n)
        for(int  i=1;i<n;i=i+2){

        }
        return answer;
    }
};
int main()
{
    Solution s;
    s.generateParenthesis(3);
    return 0;
}