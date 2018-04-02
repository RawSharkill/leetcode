#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int length =(int) s.length();
        if(length == 1)
        {
            return 1;
        }
        int longest = 0;
        int len = 0;
        string tmp;

        for(int i = 0; i < length; ++i)
        {
            if(longest > length - i)
            {
                break;
            }

            len = 0;
            for(int j = i + 1; j < length; ++j)
            {
                ++len;

                tmp = s.substr(i, j - i);  // !
                auto pos = tmp.find(s[j]);
                if(pos != string::npos)
                {
                    i += pos;

                    int k = j;
                    while((++k < length) && (s[i + 1] == s[k]))
                    {
                        ++i;
                    }

                    if(longest < len)
                    {
                        longest = len;
                    }

                    break;
                }

                if(j == length -1)
                {
                    longest = len + 1;
                    break;
                }
            }
        }

        return longest;
    }
};
int main(){
    Solution s;
   int x= s.lengthOfLongestSubstring("abcabcbb");
    cout<<x;
}