/*
1530. Number of Good Leaf Nodes Pairs
https://leetcode.com/problems/number-of-good-leaf-nodes-pairs/description/
*/

class Solution {
public:
    unordered_map<TreeNode*,TreeNode*>parent;
    unordered_set<TreeNode*>leaf;
    void addParent(TreeNode* root){
        if(root==NULL) return;

        if(root->left==NULL && root->right==NULL) leaf.insert(root); // store the child node

        if(root->left) parent[root->left]=root;
        addParent(root->left);
        if(root->right) parent[root->right]=root;
        addParent(root->right);
    }
    int countPairs(TreeNode* root, int distance) {
        addParent(root);
        int count=0;
        for(auto node:leaf){
            queue<TreeNode*>q;
            unordered_set<TreeNode*>visit;
            q.push(node);
            visit.insert(node);
            int d=distance+1;    // if 4 node then edge will 3, that why incremnt 1
            while(d-- && !q.empty()){
                int size=q.size();
                while(size--){
                    TreeNode* start=q.front();
                    q.pop();
                    visit.insert(start);
                    if(start!=node && leaf.count(start)) count++;
                    if(start->left &&  !visit.count(start->left)) q.push(start->left);
                    if(start->right && !visit.count(start->right)) q.push(start->right);
                    if(parent[start] && !visit.count(parent[start])) q.push(parent[start]);
                }
            }
        }
        return count/2;
        
    }
};

/*
store parent node of all node and store leaf node
then iterate leaf node, and from that leaf node go d distance from all side, left, right, and parent,
during this if get any other child then incrment count
*/