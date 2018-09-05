//注意题目要求  smallest lexicographical order. 
class Solution {
    public String findLongestWord(String s, List<String> d) {
        String longest="";
        for(String cur : d){
            int i=0;
            for(char c : s.toCharArray()){
                if(i<cur.length() && c==cur.charAt(i))i++;
            }
            if(i==cur.length() && cur.length()>=longest.length())
            if(cur.length()>longest.length() || cur.compareTo(longest)<0)
            longest=cur;    
        }
        return longest;
    }
}

//超时
/*class Solution {
    public String findLongestWord(String s, List<String> d) {
        if(s.length()==0 || s== null || d==null){
            return null;
        }

        int maxlength=0;
        String res="";
        char[]sarray=s.toCharArray();
        for(String x : d){
            char[]term=x.toCharArray();
            int i=0;
            int j=0;
            while(i<s.length())
            {
                if(term[j]==sarray[i])
                {
                    i++;
                    j++;
                }
                i++;
            }
            if(j==x.length()-1)
            {
                if(x.length()>maxlength)
                 res=x;
            }
        }
        return res;
    }
}
*/