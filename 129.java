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
    public int sumNumbers(TreeNode root) {
        return answer(root,0);
    }

    public int answer(TreeNode root, int maxN){
        if(root == null){
            return 0;
        }
        maxN = maxN*10 + root.val;
        if(root.left == null && root.right == null){
            return maxN;
        }else{
            return (answer(root.left,maxN) + answer(root.right,maxN));
        }
    }
}