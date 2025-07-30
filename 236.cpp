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
    
    bool findPath(vector<TreeNode*>& vc, TreeNode* root, TreeNode* point){
        if(root == NULL){
            return false;
        }

        vc.push_back(root);
        if(root == point){
            return true;
        }

        if(findPath(vc,root->left,point) || findPath(vc,root->right, point)){
            return true;
        }

        vc.pop_back();
        return false;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        

        vector<TreeNode*> vc1;
        vector<TreeNode*> vc2;

        if(!findPath(vc1,root,p) || !findPath(vc2,root,q)){
            return NULL;
        }

        int size = min(vc1.size(),vc2.size());
        TreeNode* lca = NULL;

        for(int i = 0; i < size; i++){
            if(vc1[i] == vc2[i]){
                lca = vc1[i];
            }
        }

        return lca;


    }
};