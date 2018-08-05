#include<iostream>
#include<string>
using namespace std;
/*
如果用DP 的话，要有三层循环，v[i][j][len] 意思是s1以i 为开头，s2以j为开头，长度为len 的两端字符是否为scramble string 。
*/
class Solution {
public:
	bool isScramble(string s1, string s2) {
		if (s1 == s2)
			return true;

		int len = s1.length();
		int count[26] = { 0 };
		for (int i = 0; i<len; i++)
		{
			count[s1[i] - 'a']++;
			count[s2[i] - 'a']--;
		}

		for (int i = 0; i<26; i++)
		{
			if (count[i] != 0)
				return false;
		}

		for (int i = 1; i <= len - 1; i++)
		{
			if (isScramble(s1.substr(0, i), s2.substr(0, i)) && isScramble(s1.substr(i), s2.substr(i)))
				return true;
			if (isScramble(s1.substr(0, i), s2.substr(len - i)) && isScramble(s1.substr(i), s2.substr(0, len - i)))
				return true;
		}
		return false;
	}
};