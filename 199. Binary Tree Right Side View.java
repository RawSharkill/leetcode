import java.util.ArrayList;

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
/*
最右遍历，找到写入结果的条件
*/
class Solution {
    public List<Integer> rightSideView(TreeNode root) {
        List<Integer> res=new ArrayList<Integer>();
        r(res,root,0);
        return res;
    }
    public void r(List<Integer>res,TreeNode root,int level){
        if(root==null)
        return;
        if(res.size()==level)
        res.add(root.val);
        r(res,root.right,level+1);
        r(res,root.left,level+1);
    }
}
