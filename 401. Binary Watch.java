import java.io.StringReader;
import java.util.LinkedList;
import java.util.List;

class Solution {
    public List<String> readBinaryWatch(int num) {
        List<String> res=new LinkedList<>();
        for(int h=0;h<12;h++){
            for(int m=0;m<60;m++){
                if(Integer.bitCount(h*64+m)==num)
                res.add(String.format("%d:%2d",h,m));
            }
        }
        return res;
    }
}