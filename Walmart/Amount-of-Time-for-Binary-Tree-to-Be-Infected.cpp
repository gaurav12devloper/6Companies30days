/*
2385. Amount of Time for Binary Tree to Be Infected
https://leetcode.com/problems/amount-of-time-for-binary-tree-to-be-infected/description/?envType=daily-question&envId=2024-01-10
*/
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
    unordered_map<TreeNode*,TreeNode*>parent;
    void addparent(TreeNode* root){
        if(!root) return;
        if(root->left) parent[root->left]=root;
        if(root->right) parent[root->right]=root;
        addparent(root->left);
        addparent(root->right);
    }
    int time=0;
    TreeNode* findstart(TreeNode* root,int start){
        if(!root) return NULL;
        if(root->val==start) return root;
    
        TreeNode* left=findstart(root->left,start);
        if(left) return left;
        TreeNode* right=findstart(root->right,start);
        if(right) return right;
        return NULL;
    }
    int amountOfTime(TreeNode* root, int start) {
        addparent(root);
        TreeNode* s=findstart(root,start);
        int time=0;
        queue<TreeNode*>q;
        unordered_set<TreeNode*>visit;
        q.push(s);
        while(!q.empty()){
            int size=q.size();
            while(size){
                TreeNode* node=q.front();
                q.pop();
                visit.insert(node);
                if(node->left!=NULL && !visit.count(node->left)) q.push(node->left);
                if(node->right!=NULL && !visit.count(node->right)) q.push(node->right);
                if(parent[node] && !visit.count(parent[node])) q.push(parent[node]);
                size--;
            }
            time++;
        }
        return time-1;
    }
};

/*
approach: 1)find parent node of element
2) find start node i.e infected node
3) traverse from infected node until all node become visited, since i use level order traversal
so i will get time for infecting all node
*/