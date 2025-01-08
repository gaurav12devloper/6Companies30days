/*
297. Serialize and Deserialize Binary Tree
https://leetcode.com/problems/serialize-and-deserialize-binary-tree/description/
*/
class Codec {
public:

    void buildString(TreeNode* root, string& ans){
        if(!root){
            ans+="null,";
            return;
        }
        ans+=to_string(root->val)+",";
        buildString(root->left,ans);
        buildString(root->right,ans);
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans;
        buildString(root,ans);
        return ans;
    }


    TreeNode* buildtree(queue<string>&q){
        string s=q.front();
        if(s=="null"){
            q.pop();
            return nullptr;
        }
        q.pop();
        TreeNode* root=new TreeNode(stoi(s));
        root->left=buildtree(q);
        root->right=buildtree(q);
        return root;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        queue<string>q;
        string temp;
        for(char ch:data){
            if(ch==','){
                q.push(temp);
                temp.clear();
            }
            else temp+=ch;
        }
        if (!temp.empty()) {   // Ensure the last value is added to the queue
            q.push(temp);
        }
        return buildtree(q);
    }
};