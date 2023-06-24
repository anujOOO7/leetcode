class Solution {
public:
    int dp[21][10001];
    int f(int i,int s,vector<int>& rods){
        if(i==rods.size()){
            if(s==0) return 0;
            else return INT_MIN;
        }

        int &d=dp[i][s+5000];
        if(d!=-1) return d;
        int ans=INT_MIN;
        ans=max({ans,f(i+1,s,rods),f(i+1,s+rods[i],rods),rods[i]+f(i+1,s-rods[i],rods)});
        return d=ans;
    }
    int tallestBillboard(vector<int>& rods) {
        memset(dp,-1,sizeof(dp));
        return f(0,0,rods);
    }
};