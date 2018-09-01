/*
在有序数组中查找可以采用二分法。
*/
class Solution {
    public char nextGreatestLetter(char[] a, char x) {
      int size=a.length;
      if(x>=a[size-1])
      return a[0];
   
      int s=0; 
      int e=size-1;
      while(s<e){
        int mid = s + (e - s) / 2;
        if (a[mid] > x)     e = mid;
        else    s = mid + 1;      
      }
      return a[e];
    }
}