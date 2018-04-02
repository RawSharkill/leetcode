#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
class Solution
{
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int len = (int)nums.size();
        int result = INT_MAX, close = INT_MAX;
        for (int current = 0; current < len - 2; current++) {
            int front = current + 1, back = len - 1;
            while (front < back) {
                int sum = nums[current] + nums[front] + nums[back];
                if (sum < target) {
                    if (target - sum < close) {
                        close = target - sum;
                        result = sum;
                    }
                    front++;
                }
                else if (sum > target) {
                    if (sum - target < close) {
                        close = sum - target;
                        result = sum;
                    }
                    back--;
                }
                else {
                    close = 0;
                    result = target;
                    do {
                        front++;
                    } while (front < back&&nums[front - 1] == nums[front]);
                    do {
                        back--;
                    } while (front < back&&nums[back + 1] == nums[back]);
                }
            }
            while (current < len - 2 && nums[current + 1] == nums[current]) {
                current++;
            }
        }
        return result;
    }
};