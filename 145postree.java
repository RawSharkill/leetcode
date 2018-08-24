class Solution {
    public List<Integer> postorderTraversal(TreeNode root) {
        Stack<TreeNode> sk = new Stack<>();
        List<Integer> list = new ArrayList<Integer>();
        if (root != null) sk.push(root);
        while(!sk.empty()) {
            TreeNode e = sk.pop();
            list.add(0, e.val);
            if (e.left != null) sk.push(e.left);
            if (e.right != null) sk.push(e.right);
        }
        return list;
    }
}