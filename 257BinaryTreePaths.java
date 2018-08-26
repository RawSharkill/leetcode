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
    public List<String> binaryTreePaths(TreeNode root) {
        List<String> res=new LinkedList<String>();
    
        if(root==null)
        return res;
        if(root.left==null&&root.right==null)
        {
            res.add(root.val+"");
            return res;
        }
        for(String path: binaryTreePaths(root.left))
        {
            res.add(root.val+"->"+path);
        }
        for(String path: binaryTreePaths(root.right))
        {
            res.add(root.val+"->"+path);
        }
        return res;
    }
}