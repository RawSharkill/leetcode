

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
 注意计算的位置，什么时候*10呢？？

 if(root.left==null&&root.right==null)
        return num*10+root.val;
            
sum+=dfs(root.left,num*10+root.val);
sum+=dfs(root.right,num*10+root.val);

 */
class Solution{
public int sumNumbers(TreeNode root) 
	{
		return dfs(root,0);
	}
	
	int dfs(TreeNode root,int num)
	{
		if(root==null) return 0;
		if(root.left==null&&root.right==null)
			return num*10+root.val;//之前的数字*10再加上现在的叶子结点的
		int sum=0;
		sum+=dfs(root.left,num*10+root.val);//递归左边和右边，用SUM记录总的值。
		sum+=dfs(root.right,num*10+root.val);
		return sum;
    }
}