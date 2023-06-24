class Solution {
public:
    vector<int> dx{-1,0,1,0,-1,-1,1,1};
    vector<int> dy{0,1,0,-1,-1,1,1,-1};
    
    void dfs(int i,int j,vector<vector<char>>& board){
        if(i<0 || i>=board.size() || j<0 || j>=board[0].size()) return;
        if(board[i][j]=='M'){
            board[i][j]='X';
            return;
        }
        if(board[i][j]=='E'){
            int cnt=countMine(i,j,board);
            if(cnt==0){
                board[i][j]='B';
                for(int k=0;k<8;k++) dfs(i+dx[k],j+dy[k],board);
            }
            else{
                board[i][j]=cnt+'0';
                return;
            }
        }
    }
    
    int countMine(int i,int j,vector<vector<char>>& board) {
        int count=0;
        for(int k=0;k<8;k++){
            int x=i+dx[k];
            int y=j+dy[k];
            if ((x>=0 && y>=0 && x<board.size() && y<board[0].size()) && board[x][y]=='M')
                count++;
        }
        return count;
    }
    
    vector<vector<char>> updateBoard(vector<vector<char>>& board,vector<int>& click){
        dfs(click[0],click[1],board);
        return board;
    }
};