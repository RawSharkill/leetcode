import com.sun.java.swing.plaf.nimbus.NimbusLookAndFeel;

class Solution {
    public int minSubArrayLen(int s, int[] nums) {
      if(s==0 || nums==null)
      return 0;

      int i=0;//start
      int j=0;//end
      int sum=0;
      int size=Integer.MAX_VALUE;
      while(j<nums.length){
          sum+=nums[j];
          while(sum>=s){
              size=Math.min(size, j-i);
              sum-=nums[i++];
          }
          j++;
      }
      return size==Integer.MAX_VALUE ? 0 : size;
    }
}
/*
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
*/