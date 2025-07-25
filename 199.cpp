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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(root==NULL){
            return ans;
        }
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int size = q.size();
            vector<int> vc;

            for(int i = 0; i < size; i++){
                TreeNode* tmp = q.front();
                q.pop();

                if(tmp->left!=NULL){
                    q.push(tmp->left);
                }
                if(tmp->right!=NULL){
                    q.push(tmp->right);
                }

                vc.push_back(tmp->val);
            }

            ans.push_back(vc[vc.size()-1]);

            
        }
        return ans;
    }
};