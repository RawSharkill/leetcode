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
    public TreeNode buildTreePostIn(int[] inorder, int[] postorder) {
        if (inorder == null || postorder == null || inorder.length != postorder.length)
            return null;
        HashMap<Integer, Integer> hm = new HashMap<Integer,Integer>();
        for (int i=0;i<inorder.length;++i)
            hm.put(inorder[i], i);
        return buildTreePostIn(inorder, 0, inorder.length-1, postorder, 0, 
                              postorder.length-1,hm);
    }
    
    private TreeNode buildTreePostIn(int[] inorder, int is, int ie, int[] postorder, int ps, int pe, 
                                     HashMap<Integer,Integer> hm){
        if (ps>pe || is>ie) return null;
        TreeNode root = new TreeNode(postorder[pe]);
        int ri = hm.get(postorder[pe]);
        TreeNode leftchild = buildTreePostIn(inorder, is, ri-1, postorder, ps, ps+ri-is-1, hm);
        TreeNode rightchild = buildTreePostIn(inorder,ri+1, ie, postorder, ps+ri-is, pe-1, hm);
        root.left = leftchild;
        root.right = rightchild;
        return root;
    }
}
/*
class Solution {
  public TreeNode buildTree(int[] in, int[] post) {
    if (in == null || in.length == 0 || post == null || post.length == 0) { return null; }
    return helper(post, post.length - 1, in, 0, in.length - 1);
  }
  private TreeNode helper(int[] post, int idx, int[] in, int start, int end) {
    if (start > end || idx < 0) { return null; }
    TreeNode root = new TreeNode(post[idx]);
    int i;
    for (i = start; i <= end; i++) {
      if (in[i] == root.val) {
        break;
      }
    }
    root.right = helper(post, idx - 1, in, i + 1, end);
    root.left = helper(post, idx - (end - i  + 1), in, start, i - 1);
    return root;    
  }
}
*/
