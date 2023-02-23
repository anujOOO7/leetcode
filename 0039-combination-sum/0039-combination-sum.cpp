class Solution {
public:
    vector<vector<int>> ans;
    
    void gen(vector<int> &c,vector<int> &temp,int i,int target){
        if(target==0){
            ans.push_back(temp);
            return ;
        }
        
        if(target<0)
            return;
        
        if(i==c.size())
            return ;
        
        //not inserting
        gen(c,temp,i+1,target);
        
        //inserting candidates
        temp.push_back(c[i]);
        gen(c,temp,i,target-c[i]);
        temp.pop_back();
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        gen(candidates,temp,0,target);
        return ans;
    }
};