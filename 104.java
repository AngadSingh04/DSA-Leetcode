/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public int maxDepth(TreeNode root) {

        if(root == null){
            return 0;
        }
        int leftDepth = maxDepth(root.left);
        int rightDepth = maxDepth(root.right);

        return 1 + Math.max(leftDepth, rightDepth);




        // if(root == null){
        //     return 0;
        // }
        // Queue<TreeNode> qu = new LinkedList<>();
        // qu.add(root);
        // int count = 0;

        // while(!qu.isEmpty()){
        //     int size = qu.size();
        //     for(int i = 0; i < size; i++){
        //         TreeNode temp = qu.poll();
        //         if(temp.left!=null){
        //         qu.add(temp.left);
        //         }
        //         if(temp.right!=null){
        //         qu.add(temp.right);
        //         }
        //     }

        //     count = count+1;
        // }
        // return count;
    }
}