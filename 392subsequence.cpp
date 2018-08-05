#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Solution {
public:
	bool isSubsequence(string s, string t) {
		if (s.size() == 0)
			return true;
		int indexs = 0;
		int indext = 0;
		while (indext < t.size()) {
			if (t[indext] == s[indexs]) {
				indexs++;
				if (indexs == s.size())
					return true;
			}
			indext++;
		}
		return false;
	}
};