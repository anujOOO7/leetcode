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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return {};
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);
        int flag=0;
        
        while(!q.empty()){
            int sz=q.size();
            vector<int> temp(sz);
           
            for(int i=0;i<sz;i++){
                auto x=q.front();
                q.pop();
                
                temp[i]=x->val;
                if(x->left) q.push(x->left);
                if(x->right) q.push(x->right);
            }
            if(flag) reverse(temp.begin(),temp.end());
            ans.push_back(temp);
            flag^=1;
        }
        return ans;
    }
};