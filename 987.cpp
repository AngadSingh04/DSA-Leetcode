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

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>> mp;
        queue<pair<TreeNode*, pair<int,int>>> q;

        // int x = 0;
        // int y = 0;
        q.push({root,{0,0}});

        while(!q.empty()){
            auto temp = q.front();
            q.pop();

            TreeNode* node = temp.first;

            int x = temp.second.first;
            int y = temp.second.second;

            mp[x][y].insert(node->val);
            if(node->left != NULL){
                q.push({node->left,{x-1,y+1}});
            }
            if(node->right != NULL){
                q.push({node->right,{x+1,y+1}});
            }
        }

        vector<vector<int>> ans;

        for(const auto& p: mp){
            vector<int> vc;
            for(const auto& a: p.second){
                vc.insert(vc.end(),a.second.begin(),a.second.end());
            }

            ans.push_back(vc);
        }

        return ans;
    }
};