
class Solution {
    public int mySqrt(int x) {
        if(x<=0)
        return 0;
       
        int left=1;
        int right=x;
        while(left+1<right){
            int mid=(left+right)/2;

            if(x/mid==mid)
            return mid;
            if(x/mid>mid)
            left=mid;
            if(x/mid<mid)
            right=mid;
        }
        return left;
    }
}
/*
public int sqrt(int x) {
    if (x == 0)
        return 0;
    int left = 1, right = Integer.MAX_VALUE;
    while (true) {
        int mid = left + (right - left)/2;
        if (mid > x/mid) {
            right = mid - 1;
        } else {
            if (mid + 1 > x/(mid + 1))
                return mid;
            left = mid + 1;
        }
    }
}
*/