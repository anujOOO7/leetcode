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
    vector<string> ans;
    void f(TreeNode* root,string temp){
        if(!root->left && !root->right){
            temp+=to_string(root->val);
            ans.push_back(temp);
            return;
        }
        if(root->left) f(root->left,temp+to_string(root->val)+"->");
        if(root->right) f(root->right,temp+to_string(root->val)+"->");
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        f(root,"");
        return ans;
    }
};