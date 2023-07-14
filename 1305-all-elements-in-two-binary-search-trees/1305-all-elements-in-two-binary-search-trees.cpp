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
    vector<int> ans;
    void f(TreeNode* root){
        if(!root) return;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int sz=size(q);
            
            for(int i=0;i<sz;i++){
                auto node=q.front();
                q.pop();
                ans.push_back(node->val);
                
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
        }
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        f(root1);
        f(root2);
        sort(ans.begin(),ans.end());
        return ans;
    }
};