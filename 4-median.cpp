//
// Created by yutianpig on 18-3-24.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <stdlib.h>
#include <string>
using namespace std;

double findKth(vector<int>a, int m,vector<int>b, int n, int k)
{
    //always assume that m is equal or smaller than n
    if (m > n)
        return findKth(b, n, a, m, k);
    if (m == 0)
        return b[k - 1];
    if (k == 1)
        return min(a[0], b[0]);
    //divide k into two parts
    int pa = min(k / 2, m), pb = k - pa;
    if (a[pa - 1] < b[pb - 1])
    {
        a.erase(a.begin(),a.begin()+pa);
        return findKth(a, m - pa, b, n, k - pa);
    }
    else if (a[pa - 1] > b[pb - 1])
    {
        b.erase(b.begin(),b.begin()+pb);
        return findKth(a, m, b, n - pb, k - pb);
    }
    else
        return a[pa - 1];
}

class Solution
{
public:
    double findMedianSortedArrays(vector<int>nums1, vector<int>nums2)
    {
        int m=(int)nums1.size();
        int n=(int)nums2.size();
        int total = m + n;

        if (total & 0x1)
            return findKth(nums1, m, nums2, n, total / 2 + 1);
        else
            return (findKth(nums1, m, nums2, n, total / 2)
                    + findKth(nums1, m,nums2, n, total / 2 + 1)) / 2;
    }
};
