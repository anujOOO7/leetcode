class Solution {
public:
    unordered_map<string,double> m;
    int moves[8][8]={{-2,-1},{-1,-2},{1,-2},{2,-1},{2,1},{1,2},{-1,2},{-2,1}};
    double f(int n,int k,int r,int c) {
        if(r<0 || r>=n || c<0 || c>=n) return 0;
        if(k==0) return 1;
        
        string key=to_string(r)+" "+to_string(c)+" "+to_string(k);
        if(m.find(key)!=m.end()) return m[key];
        
        double p=0;
        for(int i=0;i<8;i++) p+=f(n,k-1,r+moves[i][0],c+moves[i][1])/8.0;
        return m[key]=p;
    }
    
    double knightProbability(int n, int k, int row, int column) {
        return f(n,k,row,column);
    }
};