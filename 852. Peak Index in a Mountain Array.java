class Solution {
    public int peakIndexInMountainArray(int[] A) {
        if(A.length==0)return 0;
        int s=0;
        int e=A.length-1;

        while(s<e){
            int mid=s+(e-s)/2;
            if(A[mid-1]<A[mid] && A[mid+1]>A[mid])
            s=mid+1;
            if(A[mid-1]>A[mid] && A[mid]>A[mid+1])
            e=mid-1;
            if(A[mid-1]<A[mid] && A[mid]>A[mid+1])
            return mid;
        }
        return e;
    }
    
}