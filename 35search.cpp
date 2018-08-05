#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(nums.size() == 0) return 0;
        int lo = 0,hi = nums.size()-1;
        while(lo <= hi)
        {
            int mid = hi - ((hi - lo) >> 2);
            if(nums.at(mid) > target) hi = mid - 1;
            else if(nums.at(mid) < target) lo = lo + 1;
            // nums[mid] == targrt
            else
                return mid;
        }
        return lo;
    }
};