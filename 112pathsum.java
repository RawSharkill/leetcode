/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
/*
递归
判断各种空的情况
判断一般情况，对于某一个结点，选择它的左边结点或者选择它的右边结点，
*/
class Solution {
    public boolean hasPathSum(TreeNode root, int sum) {
        if(root==null)
        return false;
        if(root.left==null&&root.right==null&&sum-root.val==0)
        return true;

        return hasPathSum(root.left, sum-root.val) || hasPathSum(root.right, sum-root.val);
    }
}