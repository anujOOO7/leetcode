class Solution {
public:
    int dp[2001][2001];
    vector<int> nums;
    bool f(int i,int k){
        if(k<=0 || i==size(nums)) return false;
        if(i==size(nums)-1) return true;
        
        if(dp[i][k]!=-1) return dp[i][k];
        int ind=find(nums.begin(),nums.end(),nums[i]+k)-nums.begin();
        return dp[i][k]=f(ind,k-1) | f(ind,k) | f(ind,k+1);
    }
    bool canCross(vector<int>& stones) {
        nums=stones;
        memset(dp,-1,sizeof(dp));
        return f(0,1);
    }
};