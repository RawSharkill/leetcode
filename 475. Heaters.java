
import java.util.Arrays;

class Solution {
    public int findRadius(int[] houses, int[] heaters) {
        Arrays.sort(heaters);
        int res=Integer.MIN_VALUE;

        for(int house:houses){
            int index=Arrays.binarySearch(heaters, house);
            if(index<0){
                index=-(index+1);
            }

            int left=index-1>=0 ?  house-heaters[index-1] : Integer.MAX_VALUE;//保证index的左边有heaters
            int right=index<heaters.length ? heaters[index]-house : Integer.MAX_VALUE;//保证Index的右边有heaters

            res=Math.max(res, Math.min(left, right));
        }
        return res;
    }
}
/*
public class Solution {
    public int findRadius(int[] houses, int[] heaters) {
        Arrays.sort(heaters);
        int result = Integer.MIN_VALUE;
        
        for (int house : houses) {
            int index = Arrays.binarySearch(heaters, house);
            if (index < 0) {
        	index = -(index + 1);//house在hearters
            }
            int dist1 = index - 1 >= 0 ? house - heaters[index - 1] : Integer.MAX_VALUE;
            int dist2 = index < heaters.length ? heaters[index] - house : Integer.MAX_VALUE;
        
            result = Math.max(result, Math.min(dist1, dist2));
        }
        
        return result;
    }
}
*/
/*
[1] 搜索值不是数组元素，且在数组大小范围内，从0开始计数，得“ - 插入点索引值 -1”；
[2] 搜索值是数组元素，从0开始计数，得搜索值的索引值；
[3] 搜索值不是数组元素，且大于数组内元素，索引值为 – (length + 1)，其实也是 - 插入点索引值 -1，只不过在此插入点索引值为length;
[4] 搜索值不是数组元素，且小于数组内元素，索引值为 – 1( - 0 -1=-1)。
*/