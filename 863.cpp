/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void markParent(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& um){
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            auto p = q.front();
            q.pop();
            if(p->left){
                um[p->left] = p;
                q.push(p->left);
            }
            if(p->right){
                um[p->right] = p;
                q.push(p->right);
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> um;
        markParent(root, um);
        unordered_map<TreeNode*, bool> vis;
        queue<TreeNode*> q;
        q.push(target);
        vis[target] = true;
        int cnt = 0;

        while(!q.empty()){
            int size = q.size();
            if(cnt == k) break;
            cnt++;

            for(int i = 0; i < size; i++){
                auto p = q.front();
                q.pop();
                if(p->left && vis[p->left] == false){
                    q.push(p->left);
                    vis[p->left] = true;
                }
                if(p->right && vis[p->right] == false){
                    q.push(p->right);
                    vis[p->right] = true;
                }
                if(um[p] && vis[um[p]] == false){
                    q.push(um[p]);
                    vis[um[p]] = true;
                }
            }
        }

        vector<int> ans;
        while(!q.empty()){
            auto p = q.front();
            q.pop();
            ans.push_back(p->val);
        }

        return ans;
    }
};