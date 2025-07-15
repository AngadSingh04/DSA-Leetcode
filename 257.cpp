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
    void findPath(TreeNode* root, vector<int>& a, vector<vector<int>>& vc){
        if(root==NULL){
            return;
        }
        a.push_back(root->val);
        if(root->left == NULL && root->right == NULL){
            vc.push_back(a);
        }else{
            findPath(root->left, a, vc);
            findPath(root->right, a, vc);
        }

        a.pop_back();

    }
    // [[1,2,3],[1,3]];
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<int> a;
        vector<vector<int>> vc;
        findPath(root,a,vc);
        vector<string> ans;

        for(int i = 0; i < vc.size(); i++){
            string k = "";
            for(int j = 0; j < vc[i].size(); j++){
                k += to_string(vc[i][j]);
                if(j != vc[i].size()-1){
                    k += "->";
                }
            }
            ans.push_back(k);
        }
        return ans;
    }
};