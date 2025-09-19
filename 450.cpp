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
    TreeNode* getHand(TreeNode* root){
        if(root->right == NULL){
            return root;
        }
        return getHand(root->right);
    }
    TreeNode* findSide(TreeNode* root){
        if(root->right == NULL){
            return root->left;
        }
        if(root->left == NULL){
            return root->right;
        }
        TreeNode* rightHand = root->right;
        TreeNode* leftHand = getHand(root->left);
        leftHand->right = rightHand;
        return root->left;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL){
            return NULL;
        }
        if(root->val == key){
            return findSide(root);
        }

        TreeNode* curr = root;
        while(curr != NULL){
            if(curr->val > key){
                if(curr->left != NULL && curr->left->val == key){
                    curr->left = findSide(curr->left);
                    break;
                }else{
                    curr = curr->left;
                }
            }else{
                if(curr->right != NULL && curr->right->val == key){
                    curr->right = findSide(curr->right);
                    break;
                }else{
                    curr = curr->right;
                }
            }
        }

        return root;
    }
};