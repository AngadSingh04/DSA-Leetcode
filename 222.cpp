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

    // But the problem is that this is O(N) and we need to get counts in less than O(N)
    void getNodes(TreeNode* root, int& count){
        if(root == NULL){
            return;
        }
        count++;
        getNodes(root->left,count);
        getNodes(root->right,count);
    }
    int countNodes(TreeNode* root) {
        int count = 0;
        getNodes(root, count);
        return count;
    }
};