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
    int deepestLeavesSum(TreeNode* root) {
        if(!root) return 0;
        queue<TreeNode*> q;
        q.push(root);
        int sum;
        
        while(!q.empty()){
            int sz=q.size();
            sum=0;
            for(int i=0;i<sz;i++){
                auto node=q.front();
                q.pop();
                sum+=node->val;
                
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
        }
        return sum;
    }
};