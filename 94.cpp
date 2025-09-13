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
    
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> pre;
        vector<int> post;
        vector<int> in;

        if (!root) return in;

        stack<pair<TreeNode*, int>> st;
        st.push({root, 1});

        while(!st.empty()){
            auto p = st.top();
            if(p.second == 1){
                st.top().second++;
                pre.push_back(p.first->val);
                if(p.first->left){
                    st.push({p.first->left, 1});
                }
            }else if(p.second == 2){
                st.top().second++;
                in.push_back(p.first->val);
                if(p.first->right){
                    st.push({p.first->right, 1});
                }
            }else{
                post.push_back({p.first->val});
                st.pop();
            }
        }

        return in;
    }
};