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
    int maxDepth(TreeNode* root) {

        if(root == NULL){
            return 0;
        }
        queue<TreeNode*> q;
        q.push(root);
        int count = 0;

        while(!q.empty()){
            int size = q.size();

            for(int i = 0; i < size; i++){
                TreeNode* tmp = q.front();
                q.pop();

                if(tmp->left != NULL){
                    q.push(tmp->left);
                }
                if(tmp->right != NULL){
                    q.push(tmp -> right);
                }
            }
            count++;
        }
        return count;
    }
};