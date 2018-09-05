import java.util.LinkedList;

import com.sun.xml.internal.bind.v2.schemagen.xmlschema.List;

/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>> res=new LinkedList<List<integer>>();

        bfs(root,0,res);
        return res;
    }
    public void bfs(TreeNode root,int level,List<List<integer>> res){
        if(root==null)
        return;
        if(level>=res.size())
        {
            res.add(new LinkedList<Integer>());
        }
        res.get(level).add(root.val);
        bfs(root.left,level+1,res);
        bfs(root.right,level+1,res);
    }
}