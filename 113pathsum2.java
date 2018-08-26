import java.util.LinkedList;

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
将所有可能递归遍历，
重点是回溯，就是把已经到叶子结点的list的判断是否符合，然后回到叶子结点的父节点，继续遍历
就要把最后有个结点及时的去掉。
*/

class Solution {
    public List<List<Integer>> pathSum(TreeNode root, int sum) {
        List<List<Integer>> res=new LinkedList<List<Integer>>();
        List<Integer> cur=new LinkedList<Integer>();
        pathSum(root,sum,cur,res);
        return res;
    }
    public void pathSum(TreeNode root, int sum, List<Integer> currentResult,
		List<List<Integer>> result) {
	if (root == null)
		return;
    currentResult.add(new Integer(root.val));
    
	if (root.left == null && root.right == null && sum == root.val) {
		result.add(new LinkedList(currentResult));
		currentResult.remove(currentResult.size() - 1);
		return;
    } 
    else {
		pathSum(root.left, sum - root.val, currentResult, result);
		pathSum(root.right, sum - root.val, currentResult, result);
	}
	currentResult.remove(currentResult.size() - 1);
}
}