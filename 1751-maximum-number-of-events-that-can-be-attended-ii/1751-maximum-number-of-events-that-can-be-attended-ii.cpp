class Solution {
public:
    vector<vector<int>> dp;
    int f(int i,int k,vector<vector<int>> &events){
        if(i>=events.size()) return 0;
        if(k<=0) return 0;
        
        int &d=dp[i][k];
        if(d!=-1) return d;
        int ans=f(i+1,k,events);
        vector<int> temp={events[i][1],INT_MAX,INT_MAX};
        auto j=upper_bound(events.begin(),events.end(),temp)-events.begin();
        ans=max(ans,events[i][2]+f(j,k-1,events));
        return d=ans;
    }
    
    int maxValue(vector<vector<int>>& events, int k) {
        dp.resize(events.size()+1,vector<int>(k+1,-1));
        sort(events.begin(),events.end());
        // for(auto it:events) cout<<it[0]<<" "<<it[1]<<" "<<it[2]<<endl;
        return f(0,k,events);
    }
};