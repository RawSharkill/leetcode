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
    public boolean isBalanced(TreeNode root) {
        if(root==null)
        return true;
        int left=search(root.left,0);
        int right=search(root.right,0);
        if(Math.abs(left-right)>1)
        return false;
        return isBalanced(root.left)&&isBalanced(root.right);
    }
    public int search(TreeNode node,int c){
        if(node==null)
        return c;
        return Math.max(search(node.left, c+1), search(node.right, c+1));
    }
}