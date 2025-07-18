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
    TreeNode* treeCreation(vector<int>& preorder, int preStart, int preEnd, vector<int>& inorder, int inStart, int inEnd, map<int,int>& mp){

        if(preStart > preEnd || inStart > inEnd){
            return NULL;
        }

        TreeNode* root = new TreeNode(preorder[preStart]);

        int newStart = mp[root->val];
        int newLength = newStart - inStart;

        root->left = treeCreation(preorder,preStart+1, preStart+newLength, inorder, inStart, newStart - 1, mp);
        root->right = treeCreation(preorder, preStart+newLength+1, preEnd, inorder, newStart+1, inEnd,mp);

        return root;

    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        int inSize = inorder.size();
        int preSize = preorder.size();

        //Inorder: [1, 2, 3, 5, 6, 8, 9]
        //Preorder: [5, 2, 1, 3, 8, 6, 9]

        map<int, int> mp;
        for(int i = 0; i < inSize; i++){
            mp[inorder[i]] = i;
        }

        TreeNode* root = treeCreation(preorder,0,preSize-1, inorder,0, inSize-1, mp);

        return root;
        
    }
};