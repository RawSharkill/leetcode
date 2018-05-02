//
// Created by yutianpig on 18-5-1.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int x=nums.size();
        int max=-1;
        int count=0;
        for(int i=0;i<x;i++)
        {
            if(nums[i]>max)
            {
                count++;
                max=nums[i];
                nums[count-1]=max;
            }
            else
                nums[i]=NULL;
        }
        return count;
    }
};

int main()
{
    vector<int>nums={0,1,1,1,2,2,3,4,4,4,4};
    Solution s;
    int a=s.removeDuplicates(nums);
    cout<<a;
    for(int i=0;i<a;i++)
        cout<<nums[i]<<endl;

}