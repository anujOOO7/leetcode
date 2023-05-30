class Solution {
public:
    int target;
    vector<int> c;
    vector<vector<int>> ans;
    void f(int i,int sum,vector<int> &temp){
        if(sum==target){
            ans.push_back(temp);
            return;
        }
        if(i==c.size() || sum>target) return;
        
        //inserting candidates
        temp.push_back(c[i]);
        f(i,sum+c[i],temp);
        temp.pop_back();
        
        //not inserting
        f(i+1,sum,temp);
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int t) {
        vector<int> temp;
        c=candidates,target=t;
        f(0,0,temp);
        return ans;
    }
};