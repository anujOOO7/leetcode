class Solution {
public:
    int m,n;
    vector<vector<int>> vis;
    bool dfs(int i,int j,int k,string word,vector<vector<char>>& board){
        if(k==word.size()) return true;
        if(i<0 || i>=m || j<0 || j>=n) return false;
        
        if(board[i][j]==word[k] && !vis[i][j]){
            vis[i][j]=1;
            if(dfs(i-1,j,k+1,word,board) || dfs(i+1,j,k+1,word,board) || dfs(i,j-1,k+1,word,board) || dfs(i,j+1,k+1,word,board)) return true;
            else{
                vis[i][j]=0;
                return false;
            }
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        m=board.size(),n=board[0].size();
        vis.resize(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==word[0]){
                    if(dfs(i,j,0,word,board)) return true;
                }
            }
        }
        return false;
    }
};