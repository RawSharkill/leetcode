/**
 * Definition for a binary tree node. public class TreeNode { int val; TreeNode
 * left; TreeNode right; TreeNode(int x) { val = x; } }
 */
/*
这个题目要求是镜像对称，然而我的理解是只要树的形状相同便可，没有注意到结点值得对称相同问题、
*/
class Solution {
    public boolean isSymmetric(TreeNode root) {
        return isMirror(root, root);
    }

    public boolean isMirror(TreeNode root1, TreeNode root2) {
        if (root1 == null && root2 == null)
            return true;
        if (root1 != null && root2 != null && root1.val == root2.val) {
            return (isMirror(root1.left, root2.right) && isMirror(root1.right, root2.left));
        }
        return false;
    }
}