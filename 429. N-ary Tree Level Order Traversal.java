    import java.util.LinkedList;
import java.util.Queue;

import com.sun.corba.se.impl.orbutil.graph.Node;
import com.sun.xml.internal.bind.v2.schemagen.xmlschema.List;

    /*
    // Definition for a Node.
    class Node {
        public int val;
        public List<Node> children;

        public Node() {}

        public Node(int _val,List<Node> _children) {
            val = _val;
            children = _children;
        }
    };
    */
class Solution {
    public List<List<Integer>> levelOrder(Node root) {
        List<List<Integer>> res=new LinkedList<>();
        if(root==null)
        return res;
        Queue<Node> q=new LinkedList<>();
        q.add(root);
        while(!q.isEmpty()){
            int size=q.size();
            res.add(new LinkedList<Integer>());
            for(int i=0;i<size;i++){
                Node temp=q.poll();
                res.get(res.size()-1).add(temp.val);
                if(temp.children!=null){
                    for(Node c: temp.children){
                        q.add(c);
                    }
                }
            }
        }
        return res;
        }
}
    //递归做法超时是怎么回事呢
    /*
    class Solution {
        public List<List<Integer>> levelOrder(Node root) {
            int h=1;
            List<List<Integer>> res=new LinkedList<>();
            bfs(root,h,res);
            return res;
        }
        public void bfs(Node root,int h,List<List<Integer>> res){

            if(root==null)
            return;

            if(h>res.size()){
                res.add(new LinkedList<Integer>());
                res.get(h).add(root.val);
            }

            if(root.children!=null){
                for(Node c: root.children){
                    bfs(c,h+1,res);
                }
            }
        }
    }
    */