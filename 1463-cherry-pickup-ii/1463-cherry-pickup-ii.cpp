class Solution {
public:
    int n,m;
    vector<vector<int>> g;
    int dp[71][71][71];
    int f(int i,int j1,int j2){
        if(j1<0 || j2<0 || j1>=m || j2>=m) return -1e9;
        if(i==n-1){
            if(j1==j2) return g[i][j1];
            return g[i][j1]+g[i][j2];
        }
        
        if(dp[i][j1][j2]!=-1) return dp[i][j1][j2];
        int maxi=-1e9;
        for(int dj1=-1;dj1<=+1;dj1++){
            for(int dj2=-1;dj2<=+1;dj2++){
                int value=0;
                if(j1==j2) value=g[i][j1];
                else value=g[i][j1]+g[i][j2];
                maxi=max(maxi,value+f(i+1,j1+dj1,j2+dj2));
            }
        }
        return dp[i][j1][j2]=maxi;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        memset(dp,-1,sizeof(dp));
        g=grid,n=grid.size(),m=grid[0].size();
        return f(0,0,m-1);
    }
};