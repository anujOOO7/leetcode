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
   
    int sumAll(TreeNode *cur,int curSum)
    {
        if(!cur)    return 0;
        
       // curSum=curSum*10+cur->val;
        
        if(!cur->left && !cur->right)   return curSum*10+cur->val;
         int lSum=0,rSum=0;
        
        lSum=sumAll(cur->left,curSum*10+cur->val);
        rSum=sumAll(cur->right,curSum*10+cur->val);
        return lSum+rSum;
    }
    
    int sumNumbers(TreeNode* root)
    {
        return sumAll(root,0);
    }
};