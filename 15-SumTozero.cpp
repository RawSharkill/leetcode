#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        int len=(int)nums.size();
        if(len<3){
            return res;
        }
        sort(nums.begin(),nums.end());
        for(int i=0;i<len;i++){
            if(nums[i]>0)break;
            if(i>0 && nums[i]==nums[i-1])continue;
            int begin=i+1,end=len-1;//选择一个作为固定值，然后进行循环，two-sum的方法，前后一起进行
            while(begin<end){
                int sum=nums[i]+nums[begin]+nums[end];
                if(sum==0){
                    vector<int> t;
                    t.push_back(nums[i]);
                    t.push_back(nums[begin]);
                    t.push_back(nums[end]);
                    res.push_back(t);//把t放入res！！！！
                    begin++;end--;
                    while(begin<end && nums[begin]==nums[begin-1])begin++;
                    while(begin<end && nums[end]==nums[end+1])end--;
                }else if(sum>0){
                    end--;
                }else begin++;
            }
        }
        return res;
    }
};
int main()
{
    int n[6]={-1, 0, 1, 2, -1, -4};
    vector<int>num(n,n+6);
    Solution s;
    s.threeSum(num);
}
