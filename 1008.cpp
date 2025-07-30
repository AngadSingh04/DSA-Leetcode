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

    // TreeNode* createTree(vector<int>& preorder, int start, int end){
    //     if(start > end){
    //         return NULL;
    //     }
    //     TreeNode* root = new TreeNode(preorder[start]);
    //     int rightStart = start+1;
    //     while(rightStart <= end && preorder[rightStart] < preorder[start]){
    //         rightStart++;
    //     }

    //     root->left = createTree(preorder,start+1,rightStart-1);
    //     root->right = createTree(preorder,rightStart, end);

    //     return root;
    // }

    TreeNode* createTree(vector<int>& preorder,int& i, int& bound){
        if(i >= preorder.size() || preorder[i] > bound){
            return NULL;
        }
        TreeNode* root = new TreeNode(preorder[i++]);
        root->left = createTree(preorder,i,root->val);
        root->right = createTree(preorder,i,bound);

        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {

        if(preorder.size() == 0){
            return NULL;
        }
        int i = 0;
        int bound = INT_MAX;
        return createTree(preorder,i,bound);
        
    }
};