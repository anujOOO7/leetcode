class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {\
        vector<pair<int,int>> ans;
        for(int i=0;i<mat.size();i++){
            int sum=0;
            for(int j=0;j<mat[0].size();j++){
                sum+=mat[i][j];
            }
            ans.push_back({sum,i});
        }
        sort(ans.begin(),ans.end());                                                     vector<int> res;  
        for(auto [x,y]:ans){
            res.push_back(y);
        }    
        return vector<int> (res.begin(),res.begin()+k);
    }
};