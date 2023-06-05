class Solution {
public:
    vector<int> nums;
    int dp[2501][2501];
    int f(int i,int prev_ind){
        if(i==nums.size()) return 0;
        
        int &d=dp[i][prev_ind+1];
        if(d!=-1) return d;
        int len=f(i+1,prev_ind);
        if(prev_ind==-1 || nums[i]>nums[prev_ind]){
            len=max(len,1+f(i+1,i));
        }
        return d=len;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        int dp[n+1][n+1];
        memset(dp,0,sizeof(dp));
        
        for(int i=n-1;i>=0;i--){
            for(int j=i-1;j>=-1;j--){
                int count=dp[i+1][j+1];
                if(j==-1 || nums[i]>nums[j]) count=max(count,1+dp[i+1][i+1]);
                dp[i][j+1]=count;
            }
        }
        return dp[0][0];
    }
};