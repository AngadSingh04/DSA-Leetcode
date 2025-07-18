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
    TreeNode* createTree(vector<int>& postorder, int postStart, int postEnd, vector<int>& inorder, int inStart, int inEnd, map<int,int>& mp){

        if(postStart > postEnd || inStart > inEnd){
            return NULL;
        }

        TreeNode* root = new TreeNode(postorder[postEnd]);
        int newLength = mp[root->val]; // 3
        int newStart = newLength - inStart; // 3

        root->left = createTree(postorder,postStart,postStart+newStart-1, inorder, inStart, newLength - 1, mp);
        root->right = createTree(postorder, postStart+newStart, postEnd-1, inorder, newLength+1, inEnd, mp);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {

        // 40 20 50  10  60 30 --> inorder
        // 40 50 20  60 30  10 --> postorder

        // 40 20 50
        // 40 50 20

        map<int,int> mp;
        int inSize = inorder.size();
        int postSize = postorder.size();
        for(int i = 0; i < inSize; i++){
            mp[inorder[i]] = i;
        }

        TreeNode* root = createTree(postorder, 0, postSize-1, inorder, 0, inSize-1 ,mp);
        return root;
    }
};