class Solution {
public:
    int dp[501][501];
    int f(int i,int j,vector<int>& nums){
        if(i==nums.size()) return 0;
        
        int &d=dp[i][j];
        if(d!=-1) return d;
        return d=max(nums[i]*j+f(i+1,j+1,nums),0+f(i+1,j,nums));
    }
    int maxSatisfaction(vector<int>& s) {
        sort(s.begin(),s.end());
        memset(dp,-1,sizeof(dp));
        return f(0,1,s);
    }
};