import java.util.LinkedList;
import java.util.Queue;

import javax.swing.tree.TreeNode;

import sun.reflect.generics.tree.Tree;

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
    int h=0;
    int ans=0;
    public int findBottomLeftValue(TreeNode root) {
       bfs(root,1);
       return ans;
    }
    public void bfs(TreeNode root,int level){
        if(h<level){
            ans=root.val;
            h=level;
        }
        if(root.left!=null)bfs(root.left,level+1);
        if(root.right!=null)bfs(root.right,level+1);
    }
}