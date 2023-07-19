class Solution {
public:
    int n;
    vector<int> temp;
    int dp[100001];
    int f(int i,vector<vector<int>>& intervals){
        if(i>=n) return 0;
        
        if(dp[i]!=-1) return dp[i];
        int ans=INT_MIN;
        ans=max(ans,0+f(i+1,intervals));
        auto it=lower_bound(temp.begin(),temp.end(),intervals[i][1])-temp.begin();
        ans=max({ans,1+f(it,intervals)});
        return dp[i]=ans;
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        memset(dp,-1,sizeof(dp));
        n=intervals.size();
        sort(intervals.begin(),intervals.end());
        for(auto i:intervals) temp.push_back(i[0]);
        return n-f(0,intervals);
    }
};