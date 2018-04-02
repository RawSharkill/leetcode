//
// Created by yutianpig on 18-3-29.
//
#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) {
        int left=0;
        int right=(int)(height.size()-1);
        if(height.size()<2)
            return 0;
        int temp=0;
        int result=0;
        while(left<right){
            temp=(right-left)*min(height[left],height[right]);
            result=max(temp,result);
            if(height[left]<height[right])
                left++;
            else
                right--;
        }
        return result;
    }
};



