public class Solution {
    public int findMin(int[] num) {
        int low = 0;
        int high = num.length - 1;
        while(low < high){
            int mid = (low + high) / 2;
            if(num[high] < num[mid]){
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return num[high];
    }
}
/*
public int searchMinRotatedArray(int[] array, int start ,int end){
    if(start == end) return array[start];
    int mid = (start+end)/2;
    if(array[mid] < array[end])
        return searchMinRotatedArray(array, start, mid);
    else 
        return searchMinRotatedArray(array, mid+1, end);
    
}
*/