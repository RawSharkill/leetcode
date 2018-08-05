//
// Created by yutianpig on 18-3-31.
//
#include <iostream>
#include <vector>
using namespace std;

/*class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<vector<char>> nums;
        nums[2]={'a','b','c'};
        nums[3]={'d','e','f'};
        nums[4]={'g','h','i'};
        nums[5]={'j','k','l'};
        nums[6]={'m','n','o'};
        nums[7]={'p','q','r','s'};
        nums[8]={'t','u','v'};
        nums[9]={'w','x','y','z'};
        int i=0;
        while(digits[i]!=NULL){
            int temp=(int)digits[i];

        }
    }
};*/

class Solution {
    static string letter[10];
    vector<string> res;
public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty())
            return res;
    	string str;
    	combine(digits, 0, str);
    	return res;
    }

    void combine(string &digits, int i, string str) {
    	if(i>=digits.size()) {   // 递归终止条件
    		res.push_back(str);
    		return;
    	}
    	string s = letter[digits[i]-'0'];
    	for(int j=0; j<s.size(); ++j)//例如： 已经有的字符串是def，此时输入的数字是2，那么应该有：defa,defb,defc;
    		combine(digits, i+1, str+s[j]);
    }
};

string Solution::letter[] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
