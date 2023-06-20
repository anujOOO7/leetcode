class Solution {
public:
    int m,n;
    vector<vector<int>> vis;
    vector<int> dx{-1,0,0,1};
    vector<int> dy{0,-1,1,0};
    void f(int i,int j,vector<vector<char>>& board){
        if(i>=0 && i<m && j>=0 && j<n && board[i][j]=='O' && !vis[i][j]){        
            vis[i][j]=1;
            for(int p=0;p<4;p++){
                int ni=i+dx[p],nj=j+dy[p];
                f(ni,nj,board);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        m=board.size(),n=board[0].size();
        vis.resize(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if((i==0 || i==m-1 || j==0 || j==n-1) && board[i][j]=='O' && !vis[i][j]){
                    f(i,j,board);
                }
            }
        }
        
        // changing all O's to X's
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='O' && !vis[i][j]) board[i][j]='X';
            }
        }
    }
};