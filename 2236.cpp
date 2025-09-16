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
    bool checkTree(TreeNode* root) {
        if(root == NULL || (root->left == NULL && root->right == NULL)){
            return true;
        }
        int child = 0;
        if(root->left){
            child += root->left->val;
        }
        if(root->right){
            child += root->right->val;
        }
        if(child != root->val){
            return false;
        }

        return checkTree(root->left) && checkTree(root->right);
    }
};

// converting

class Solution {
public:
    void checkTree(TreeNode* root) {
        if(root == NULL){
            return;
        }
        int child = 0;
        if(root->left){
            child += root->left->val;
        }
        if(root->right){
            child += root->right->val;
        }
        if(child >= root->data) root->data = child;
        else{
            if(root->left) root->left->data = root->data;
            else if(root->right) root->right->data = root->data;
        }

        checkTree(root->left);
        checkTree(root->right);

        int total = 0;
        if(root->left) total += root->left->data;
        if(root->right) total += root->right->data;
        if(root->left || root->right) root->data = total;
    }
};