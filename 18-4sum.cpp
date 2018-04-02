//
// Created by yutianpig on 18-4-1.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        int len=(int)nums.size();
        if(len<4){
            return res;
        }
        sort(nums.begin(),nums.end());
        for(int j=0;j<len-3;++j){
            if(j>0&&nums[j]==nums[j-1])
                continue;
            for (int i = j + 1; i < len-2; ++i) {
                if(i>j+1&&nums[i]==nums[i-1])
                    continue;
                int begin = i + 1, end = len - 1;
                while (begin < end) {
                    int sum = nums[i] + nums[begin] + nums[end];
                    if (sum == target - nums[j]) {
                        vector<int> t;
                        t.push_back(nums[i]);
                        t.push_back(nums[begin]);
                        t.push_back(nums[end]);
                        t.push_back(nums[j]);
                        res.push_back(t);//把t放入res！！！！
                        begin++;
                        end--;
                        while(begin<end && nums[begin]==nums[begin+1])begin++;
                        while(begin<end && nums[end]==nums[end-1])end--;
                    } else if (sum > target - nums[j]) {
                        end--;
                    } else begin++;
                }
            }
        }
        return res;
    }

};
/*
 * class Solution {
    vector<vector<int>> res;
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if(nums.size() < 4)
            return res;
        sort(nums.begin(), nums.end());   // 排序
        for(int i=0; i<nums.size()-3; ++i) {
            if(i>0 && nums[i]==nums[i-1]) // 相等的跳过
                continue;
            threeSum(nums, i+1, nums[i], target);
        }
        return res;
    }

    void threeSum(vector<int>& nums, int p, int first, int target) {
        for(int i=p; i<nums.size()-2; ++i) {
            if(i>p && nums[i]==nums[i-1]) // 相等的跳过
                continue;
            twoSum(nums, i+1, nums.size()-1, first, nums[i], target);
        }
    }


    void twoSum(vector<int>& nums, int begin, int end, int first, int second, int target) {
        int i = begin;  // 头指针
        int j = end;    // 尾指针
        while(i < j) {
            if(first+second+nums[i]+nums[j]==target) {
                vector<int> v;
                v.push_back(first);
                v.push_back(second);
                v.push_back(nums[i]);
                v.push_back(nums[j]);
                res.push_back(v);
                while(i<j && nums[i]==nums[i+1])
                    ++i;  // 相等的跳过
                while(i<j && nums[j]==nums[j-1])
                    --j;  // 相等的跳过
                ++i;
                --j;
            }
            else if(first+second+nums[i]+nums[j]<target)
                ++i;
            else
                --j;
        }
    }
};
 */