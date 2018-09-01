import java.util.Arrays;

class Solution {
    public int minSubArrayLen(int s, int[] nums) {
       Arrays.sort(nums);
       int start=nums.length-1;
       int count=0;
       int sum=0;
       while(sum<s){
           sum+=nums[start];
           start--;
           count++;
       }
       return count;
    }
}