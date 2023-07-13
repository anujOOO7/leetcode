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
    int cnt=0;
    int f(TreeNode* root,int &h){
        if(!root) return 0;
        h++;
        return root->val+f(root->left,h)+f(root->right,h);
    }
    int averageOfSubtree(TreeNode* root) {
        if(!root) return 0;
        int h=0;
        int sum=f(root,h);
        if(root->val==sum/h) cnt++;
        averageOfSubtree(root->left);
        averageOfSubtree(root->right);
        return cnt;
    }
};