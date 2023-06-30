class Solution {
public:
    int n,m;
    vector<vector<int>> g;
    bool dfs(int i,int j){
        g[i][j]=2;
        if(i==0) return true;
        if(i>0 && g[i-1][j]== 1 && dfs(i-1,j)) return true;
        if(j>0 && g[i][j-1]==1 && dfs(i,j-1)) return true;
        if(i<n-1 && g[i+1][j]==1 && dfs(i+1,j)) return true;
        if(j<m-1 && g[i][j+1]==1 && dfs(i,j+1)) return true;
        return false;
    }
    int latestDayToCross(int row, int col, vector<vector<int>>& c) {
        n=row,m=col;
        g.resize(n,vector<int>(m,0));
        for(int s=c.size()-1;s>=0;--s){
            int i=c[s][0]-1,j=c[s][1]-1;
            if((i==n-1) || (i>0 && g[i-1][j]==2) || (i<n-1 && g[i+1][j]==2) || (j>0 && g[i][j-1]==2) || (j<m-1 && g[i][j+1]==2)){
                if(dfs(i,j)) return s;
            }
            else g[i][j]=1;
        }
        return 0;
    }
};