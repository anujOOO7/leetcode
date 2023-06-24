class Solution {
public:
    int dp[1001][1001];
    int f(int i,int prev,vector<vector<int>>& pairs){
        if(i==pairs.size()) return 0;
        
        int &d=dp[i][prev+1];
        if(d!=-1) return d;
        int take=0;
        if(prev==-1 || pairs[i][0]>pairs[prev][1]) take=1+f(i+1,i,pairs);
        int not_take=0+f(i+1,prev,pairs);
        return d=max(take,not_take);        
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        memset(dp,-1,sizeof(dp));
        sort(pairs.begin(),pairs.end(),[&](vector<int>& a,vector<int>& b){
            return a[1]<b[1];
        });
        return f(0,-1,pairs);
    }
};