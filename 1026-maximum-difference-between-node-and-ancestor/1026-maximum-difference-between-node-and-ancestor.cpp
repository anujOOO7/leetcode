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
    vector<int> temp;
    void f(TreeNode* root){
        if(!root){
            mx=max(mx,abs(*max_element(begin(temp),end(temp))-*min_element(begin(temp),end(temp))));
            return;
        }
            
        temp.push_back(root->val);
        f(root->left);
        f(root->right);
        temp.pop_back();
    }
    int maxAncestorDiff(TreeNode* root) {
        f(root);
        return mx;
    }
};