import java.util.ArrayList;
import java.util.HashSet;
import java.util.Iterator;
import java.util.LinkedHashSet;
/*
采用hashset存储一个数组，这样可以消除掉数组中相同的元素，便于后面的循环对比。
先用arraylist存储结果，这样可以用contains来判断结果中是否已经存在此时判的元素；
*/
class Solution {
    public int[] intersection(int[] nums1, int[] nums2) {
        if(nums1==null || nums2==null)
        return null;
        HashSet<Integer> n1=new LinkedHashSet<Integer>();
        for(Integer i:nums1)
        n1.add(i);
        ArrayList<Integer>res=new ArrayList<>();
        for(Integer j:nums2){
            if(n1.contains(j) && !res.contains(j))
            res.add(j);
        }

        int[] answer=new int[res.size()];
        for(int i=0;i<res.size();i++)
        answer[i]=res.get(i);

        return answer;
    }
}