/*
1373. Maximum Sum BST in Binary Tree
https://leetcode.com/problems/maximum-sum-bst-in-binary-tree/description/
*/
class Solution {
public:
    // {smallest_num, largest_num, curr_sum} of a tree
    vector<int> traverse(TreeNode* root, int& ans) {
        if (!root) return {INT_MAX, INT_MIN, 0};
        vector<int> left(traverse(root->left, ans)), right(traverse(root->right, ans));
		// check if a tree is BST
        if (left.empty() || right.empty() || root->val <= left[1] || root->val >= right[0]) return {};
		// if BST, update ans
        int curr_sum = left[2] + right[2] + root->val;
        ans = max(ans, curr_sum);
        return {min(left[0], root->val), max(right[1], root->val), curr_sum};
    }
    int maxSumBST(TreeNode* root) {
        int ans(0);
        traverse(root, ans);
        return max(0, ans);
    }
};