class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m=grid.size(),n=grid[0].size();
        vector<vector<int>> v(m,vector<int>(n));
        for(int i=0; i<n*m; i++){
           int temp=(i+k)%(n*m);
           v[temp/n][temp%n]=grid[i/n][i%n];
        }
        return v;
    }
};