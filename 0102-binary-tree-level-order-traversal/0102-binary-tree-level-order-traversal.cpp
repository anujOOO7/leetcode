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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return {};
        vector<vector<int>> ans;
        queue<vector<TreeNode*>> q;
        ans.push_back({root->val});
        q.push({root});
        
        while(!q.empty()){
            vector<TreeNode*> temp;
            vector<int> data;
            auto node=q.front();
            q.pop();
            
            for(auto it:node){
                if(it->left){
                    temp.push_back(it->left);
                    data.push_back(it->left->val);
                }
                if(it->right){
                    temp.push_back(it->right);
                    data.push_back(it->right->val);
                }
            }
            if(temp.size()) q.push(temp);
            if(data.size()) ans.push_back(data);
            temp.clear();
            data.clear();
        }
        return ans;
    }
};