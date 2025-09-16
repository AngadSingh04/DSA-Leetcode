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
        string s = "";
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            auto p = q.front();
            q.pop();

            if(p==NULL){
                s.append("null,");
            }else{
                s.append(to_string(p->val) + ',');
            }
            if(p != NULL){
                q.push(p->left);
                q.push(p->right);
            }
        }

        return s.substr(0, s.size()-1);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size() == 0){
            return NULL;
        }
        stringstream s(data);
        string str;
        getline(s, str, ',');
        queue<TreeNode*> q;
        TreeNode* root = new TreeNode(stoi(str));
        q.push(root);

        while(!q.empty()){
            auto p = q.front();
            q.pop();

            getline(s, str, ',');
            if(str == "null"){
                p->left = NULL;
            }else{
                TreeNode* tmp = new TreeNode(stoi(str));
                p->left = tmp;
                q.push(tmp);
            }

            getline(s,str,',');
            if(str == "null"){
                p->right = NULL;
            }else{
                TreeNode* tmp = new TreeNode(stoi(str));
                p->right = tmp;
                q.push(tmp);
            }
        }

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));