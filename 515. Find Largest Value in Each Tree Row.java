import java.util.LinkedList;
import java.util.Queue;

import javax.swing.tree.TreeNode;

import com.sun.xml.internal.bind.v2.schemagen.xmlschema.List;

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
    public List<Integer> largestValues(TreeNode root) {
        List<Integer> res=new LinkedList<Integer>();
        Queue<TreeNode> cur=new LinkedList<TreeNode>();

        if(root==null)
        return res;

        cur.offer(root);
        while(!cur.isEmpty()){
            int max=Integer.MIN_VALUE;
            int size=cur.size();
            for(int i=0;i<size;i++)
            {
                TreeNode now=cur.poll();
                max=Math.max(max,now.val);
                if(now.left!=null)cur.offer(now.left);
                if(now.right!=null)cur.offer(now.right);
            }
            res.add(max);
        }
        return res;
    }
   
}