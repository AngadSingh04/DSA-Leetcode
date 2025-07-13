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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;

        if(root == NULL){
            return ans;
        }

        queue<TreeNode*> q;
        q.push(root);
        int idx = 0;

        while(!q.empty()){
            int size = q.size();
            vector<int> vc;
            for(int i = 0; i < size; i++){
                TreeNode* temp = q.front();
                q.pop();
                if(temp->left != NULL){
                    q.push(temp->left);
                }
                if(temp->right != NULL){
                    q.push(temp->right);
                }

                vc.push_back(temp->val);
            }

            if(idx%2==0){
                ans.push_back(vc);
            }else{
                reverse(vc.begin(),vc.end());
                ans.push_back(vc);
            }
            idx++;
        }
        return ans;
    }
};