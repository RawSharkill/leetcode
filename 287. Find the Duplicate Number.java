import java.util.HashSet;

import com.sun.xml.internal.bind.v2.runtime.reflect.NullSafeAccessor;

class Solution {
    public int findDuplicate(int[] nums) {
        if(nums==null)
        return -1;
        else{
            int slow=nums[0];
            int fast=nums[nums[0]];//move twice fast
            while(slow!=fast){
                slow=nums[slow];
                //move twice fast;
                fast=nums[fast];
                fast=nums[fast];
                /*
                move once slow,move twice fast 
                当fast和slow相遇时，说明他们走进了一个圈，
                那么让他们相遇的前一个就是duplicate number;
                */
            }
            fast=0;
            //在走一遍来找进入圈的入口
            while(slow!=fast){
                slow=nums[slow];
                fast=nums[fast];
            }
            return slow;
        }      
    }
}