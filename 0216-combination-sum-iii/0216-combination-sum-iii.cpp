class Solution {
public:
    vector<vector<int>> ans;
    void gen(vector<int>& temp,int k,int ind,int target)
    {
        if(temp.size()==k)
        {
            if(target==0){
                ans.push_back(temp);
            }
            return;
        }
        
        for(int j=ind;j<=9;j++)
        {
            temp.push_back(j);
            gen(temp,k,j+1,target-j);
            temp.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum3(int k,int n) 
    {
        vector<int> temp;
        gen(temp,k,1,n);
        return ans;
    }
};