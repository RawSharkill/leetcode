#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       int *buffer = new int[sizeof(nums)*nums.size()];
        if (!nums.empty())
        {
            memcpy(buffer, &nums[0], nums.size()*sizeof(int));
        }
        int i=0,j=(int)nums.size()-1;
        sort(buffer,buffer+nums.size());
        while(i!=j){
            int n=buffer[i]+buffer[j];
            if(n==target){
                break;
            }
            if(n>target)
                j--;
            else
                i++;
        }
        vector<int>back;
        for(int x=0;x<nums.size();x++) {
            if (nums[x] == buffer[i] || nums[x] ==buffer[j]) {
                back.push_back(x);
            }
        }
        return back;
    }
};
int main() {
    vector<int>n;
    n.push_back(150);
    n.push_back(24);
    n.push_back(79);
    n.push_back(50);
    n.push_back(88);
    n.push_back(345);
    n.push_back(3);
    Solution s;
    s.twoSum(n,200);
    return 0;
}