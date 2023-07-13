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
    int sumEvenGrandparent(TreeNode* root) {
        if(!root) return 0;
        vector<TreeNode*> parent(10001,NULL);
        queue<TreeNode*> q;
        q.push(root);
        int sum=0;
        
        while(!q.empty()){
            int sz=size(q);
            
            for(int i=0;i<sz;i++){
                auto node=q.front();
                q.pop();
                
                if(node->val%2==0){
                    if(node->left && node->left->left) sum+=node->left->left->val;
                    if(node->left && node->left->right) sum+=node->left->right->val;
                    if(node->right && node->right->left) sum+=node->right->left->val;
                    if(node->right && node->right->right) sum+=node->right->right->val;
                }
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
        }
        return sum;
    }
};