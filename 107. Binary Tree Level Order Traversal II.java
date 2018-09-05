import java.util.LinkedList;

import javax.swing.tree.TreeNode;

import com.sun.xml.internal.bind.v2.schemagen.xmlschema.List;

public class Solution {
    public List<List<Integer>> levelOrderBottom(TreeNode root) {
        List<List<Integer>> res=new LinkedList<List<Integer>>();
        bfs(res,root,0);
        return res;
    }
    public void bfs(List<List<Integer>> res,TreeNode root,int level){
        if(root==null)
        return;
        if(level>=res.size())
        res.add(0,new LinkedList<Integer>());

        bfs(res,root.left,level+1);
        bfs(res,root.right,level+1);

        res.get(res.size()-level-1).add(root.val);
    }
}   