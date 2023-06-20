class Solution {
public:
    int m,n;
    vector<int> dx{-1,0,0,1};
    vector<int> dy{0,-1,1,0};
    bool f(int i,int j,int k,string word,vector<vector<char>>& board){
        if(k==word.size()) return true;
        if(i<0 || i>=m || j<0 || j>=n || board[i][j]!=word[k]) return false;
        
        char temp=board[i][j];
        board[i][j]='@';
        for(int p=0;p<4;p++){
            int ni=i+dx[p],nj=j+dy[p];
            if(f(ni,nj,k+1,word,board)) return true;
        }
        board[i][j]=temp;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        m=board.size(),n=board[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==word[0]){
                    if(f(i,j,0,word,board)) return true;
                }
            }
        }
        return false;
    }
};