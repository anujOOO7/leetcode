class Solution {
public:
    int dp[13][10001];
    int f(int i,vector<int>& c,int a){
        if(a==0) return 0;
        if(a!=0 && i==c.size()) return 1e5;
        if(dp[i][a]!=-1)
            return dp[i][a];
        
        if(a<c[i]) 
        return dp[i][a]=f(i+1,c,a);
        else
        return dp[i][a]=min(1+f(i,c,a-c[i]),f(i+1,c,a));
    }
    int coinChange(vector<int>& c,int a){
        //sort(rbegin(c),rend(c));
        memset(dp,-1,sizeof(dp));
        int ans=f(0,c,a);
        if(ans>=1e5) return -1;
        return ans;
    }
};