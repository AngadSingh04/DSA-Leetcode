/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    bool isValid(TreeNode* root, long minV, long maxV){
        if(root == NULL){
            return true;
        }
        if(root->val <= minV || root->val >= maxV){
            return false;
        }
        return isValid(root->left,minV,root->val) && isValid(root->right,root->val,maxV);
    }

    bool isValidBST(TreeNode* root) {
        if(root == NULL){
            return true;
        }
        long minV = LONG_MIN;
        long maxV = LONG_MAX;
        return isValid(root,minV,maxV);
    }
};