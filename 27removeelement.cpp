//
// Created by yutianpig on 18-5-1.
//
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        vector<int>::iterator beg = nums.begin();
        for( ; beg!=nums.end(); ) {
            if(*beg == val)
                beg = nums.erase(beg);//注意erase()的用法，它在删除迭代器后，会返回下一个元素的迭代器
            else
                ++beg;
        }
        return nums.size();
    }
};