class Solution {
public:
    int n;
    int dp[366];
    vector<int> d,c;
    int f(int i){
        if(i==n) return 0;
        
        if(dp[i]!=-1) return dp[i];
        return dp[i]=min(c[0]+f(lower_bound(d.begin(),d.end(),d[i]+1)-d.begin()),min(c[1]+f(lower_bound(d.begin(),d.end(),d[i]+7)-                       d.begin()),c[2]+f(lower_bound(d.begin(),d.end(),d[i]+30)-d.begin())));
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        n=days.size(),d=days,c=costs;
        memset(dp,-1,sizeof(dp));
        return f(0);
    }
};