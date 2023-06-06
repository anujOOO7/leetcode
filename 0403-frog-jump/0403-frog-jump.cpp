class Solution {
public:
    int dp[2001][2001];
    vector<int> nums;
    bool f(int i,int k){
        if(k<=0 || i==size(nums)) return false;
        if(i==size(nums)-1) return true;
        
        if(dp[i][k]!=-1) return dp[i][k];
        bool ans=false;
        for(int j=i+1;j<nums.size();j++){
            if(nums[j]-nums[i]==k){
                ans=f(j,k-1) | f(j,k) | f(j,k+1);
            }
        }
        return dp[i][k]=ans;
    }
    bool canCross(vector<int>& stones) {
        nums=stones;
        memset(dp,-1,sizeof(dp));
        return f(0,1);
    }
};