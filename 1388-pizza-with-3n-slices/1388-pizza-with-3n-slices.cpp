class Solution {
public:
    vector<int> slices;
    int f(int i,int len,int cnt,int dp[501][201]){
        if(i>=len || cnt<=0) return 0;
        
        int &d=dp[i][cnt];
        if(d!=-1) return d;
        return d=max(f(i+1,len,cnt,dp),slices[i]+f(i+2,len,cnt-1,dp));
    }
    int maxSizeSlices(vector<int>& s) {
        int n=s.size();
        slices=s;
        int dp1[501][201],dp2[501][201];
        memset(dp1,-1,sizeof(dp1));
        memset(dp2,-1,sizeof(dp2));
        return max(f(0,n-1,n/3,dp1),f(1,n,n/3,dp2));
    }
};