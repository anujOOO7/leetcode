class Solution {
public:
    vector<vector<int>> ans;
    vector<int> v;
    
    void gen(int n,int k,int ind)
    {
        if(v.size()==k){
            ans.push_back(v);
        return ;
        }
        
        while(ind<=n){
            //not take
            gen(n,k,ind+1);

            //take
            v.push_back(ind);
            gen(n,k,ind+1);
            v.pop_back();
            return ;
        }
    }    
    
    vector<vector<int>> combine(int n, int k) {
        int ind=1;

        gen(n,k,ind);
        return ans;
    }
};