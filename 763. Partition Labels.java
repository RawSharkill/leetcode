import java.util.ArrayList;

import com.sun.xml.internal.bind.v2.schemagen.xmlschema.List;

class Solution {
    public List<Integer> partitionLabels(String S) {
        if(S==null || S.length()==0)
        return null;
        else{
            int[]map=new int[26];
            List<Integer> res=new ArrayList<Integer>();
            for(int i=0;i<S.length();i++)
            map[S.charAt(i)-'a']=i;//记录字母最后出现的位置
            int last=0;
            int start=0;
            for(int i=0;i<S.length();i++)
            {
                last=Math.max(last, map[S.charAt(i)-'a']);
                if(last==i)
                {
                    res.add(last-start+1);
                    start=last+1;
                }
            }
            return res;
        }
    }
}