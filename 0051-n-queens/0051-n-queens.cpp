class Solution {
public:
    bool good(vector<string> b,int r,int c,int n){
        int row=r;
        int col=c;
        
        while(r>=0 && c>=0){
            if(b[r][c]=='Q')
                return false;
            r--,c--;
        }
        
        r=row,c=col;
        while(c>=0)
        {
            if(b[r][c]=='Q')
                return false;
            c--;
        }
        
        r=row,c=col;
        while(r<n && c>=0)
        {
            if(b[r][c]=='Q')
                return false;
            r++,c--;
        }
        return true;
    }
    
    void sol(vector<vector<string>> &ans,vector<string> &board,int c,int n){
        if(c==n)
        {
            ans.push_back(board);
            return;
        }
        
        for(int r=0;r<n;r++){
            if(good(board,r,c,n)){
                board[r][c]='Q';
                sol(ans,board,c+1,n);
                board[r][c]='.';
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n,'.');
        for(int i=0;i<n;i++){
            board[i]=s;
        }
        int col=0;
        sol(ans,board,col,n);
        return ans;
    }
};