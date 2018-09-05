import java.util.LinkedList;
import java.util.Queue;

import com.sun.corba.se.impl.orbutil.graph.Node;

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
    public int maxDepth(Node root) {
       return idea(root);
    }
    /*public int idea(Node root){
        if(root==null)
        return 0;
        if(root.children==null)
        return 1;
        List<Node> child=root.children;
        int max=0;
        for(Node c: child){
           max=Math.max(max, bfs(c));
        }
        return max+1;
    }*/
    public int bfs(Node root){
        if(root==null)return 0;
        Queue<Node> q=new LinkedList<Node>();
        q.add(root);
        int count=0;
        while(q.size()>0){
            int size=q.size();
            for(int i=0;i<size;i++){
                Node temp=q.poll();
                if(temp.children!=null)
                for(Node c : temp.children){
                    q.add(c);
                }
            }
            count++;
        }
        return count;
    }
}