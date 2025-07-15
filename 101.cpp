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
    vector<int> leftB(TreeNode* root, vector<int>& vc1){
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int size = q.size();
            for(int i = 0; i < size; i++){
                TreeNode* tmp = q.front();
                q.pop();

                if(tmp==NULL){
                    vc1.push_back(-1);
                    continue;
                }
                q.push(tmp->left);
                q.push(tmp->right);

                vc1.push_back(tmp->val);
            }
        }
        return vc1;
    }

    vector<int> rightB(TreeNode* root, vector<int>& vc2){
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int size = q.size();
            vector<int> vc;
            for(int i = 0; i < size; i++){
                TreeNode* tmp = q.front();
                q.pop();

                if(tmp == NULL){
                    vc2.push_back(-1);
                    continue;
                }

                q.push(tmp->right);
                q.push(tmp->left);

                vc2.push_back(tmp->val);
            }
        }
        return vc2;
    }

    bool checkS(vector<int>& vc1, vector<int>& vc2){
        int i = 0;
        int j = 0;
        int n = vc1.size();
        int m = vc2.size();
        if(n != m){
            return false;
        }
        while(i < n && j < m){
            if(vc1[i] != vc2[j]){
                return false;
            }
            i++;
            j++;
        }
        return true;
    }
    bool isSymmetric(TreeNode* root) {
        vector<int> vc1;
        vector<int> vc2;

        if(root == NULL || (root->left == NULL && root->right == NULL)){
            return true;
        }
        leftB(root->left, vc1);
        rightB(root->right, vc2);
        bool ans = checkS(vc1,vc2);
        return ans;

        // if(checkS(root)){
        //     return true;
        // }
        // return false;

        // 1 2 3 4
        // 1 2 4 3
    }
};