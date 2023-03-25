class Solution {
public:
    void zero(vector<vector<int>>& matrix,int f,int s){
        for(int j=0;j<matrix[0].size();j++){
            matrix[f][j]=0;
        }
        for(int i=0;i<matrix.size();i++){
            matrix[i][s]=0;
        }
    }
    
    void setZeroes(vector<vector<int>>& matrix) {
        int n=matrix.size(),m=matrix[0].size();
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0){
                    v.push_back({i,j});
                }
            }
        }
        for(auto it:v){
            zero(matrix,it.first,it.second);
        }
    }
};