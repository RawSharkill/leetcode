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
    public TreeNode sortedArrayToBST(int[] nums) {
        if(nums.length==0)
        return null;
        TreeNode head= Bsf(nums,0,nums.length-1);
    }
    TreeNode Bsf(int[] nums,int s,int e){
        if(s>e)
        return null;
        else{
            int mid=(s+e)/2;
            TreeNode n=new TreeNode(nums[mid]);
            n.left=Bsf(nums, s, mmid-1);
            n.right=Bsf(nums, mid+1, e);
            return n;
        }
    }
}