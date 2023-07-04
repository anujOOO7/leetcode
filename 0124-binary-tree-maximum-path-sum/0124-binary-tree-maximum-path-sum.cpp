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
    int f(TreeNode* root,int& mx){
        if(root==NULL) return 0;
        
        int lp=max(0,f(root->left,mx));
        int rp=max(0,f(root->right,mx));
        mx=max(mx,lp+rp+root->val);
        return max(lp,rp)+root->val;
    }
    int maxPathSum(TreeNode* root) {
        int mx=INT_MIN;
        f(root,mx);
        return mx;
    }
};