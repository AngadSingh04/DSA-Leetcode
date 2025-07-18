/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == NULL){
            return "";
        }
        string ans = "";
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* tmp = q.front();
            q.pop();

            if(tmp){
                ans += to_string(tmp->val)+',';
                q.push(tmp->left);
                q.push(tmp->right);
            }else{
                ans += "null,";
            }
        }
        string result = ans.substr(0,ans.size()-1);
        return result;
        
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {

        if(data == ""){
            return NULL;
        }
        stringstream ss(data);
        string str;
        getline(ss, str, ',');
        TreeNode* root = new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* tmp = q.front();
            q.pop();

            getline(ss,str,',');
            if(str == "null"){
                tmp->left = NULL;
            }else{
                TreeNode* node = new TreeNode(stoi(str));
                tmp->left = node;
                q.push(node);
            }

            getline(ss,str,',');
            if(str == "null"){
                tmp->right = NULL;
            }else{
                TreeNode* node = new TreeNode(stoi(str));
                tmp->right = node;
                q.push(node);
            }
        }

        return root;
        
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));