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
    int mx=0;
    void f(TreeNode* root,TreeNode* node){
        if(!root || !node) return;
        int diff=abs(root->val-node->val);
        mx=max(mx,diff);
        f(root,node->left);
        f(root,node->right);
    }
    int maxAncestorDiff(TreeNode* root) {
        if(!root) return 0;
        f(root,root->left);
        f(root,root->right);
        maxAncestorDiff(root->left);
        maxAncestorDiff(root->right);
        return mx;
    }
};