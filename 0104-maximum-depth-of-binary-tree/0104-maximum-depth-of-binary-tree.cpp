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
    int ans=0;
    void f(TreeNode* root,int cnt){
        if(root==NULL) return;
        
        f(root->left,cnt+1);
        if(root->left==NULL && root->right==NULL){
            ans=max(ans,cnt);
            cnt--;
        }
        f(root->right,cnt+1);
    }
    int maxDepth(TreeNode* root) {
        if(root==NULL) return 0;
        f(root,1);
        return ans;
    }
};