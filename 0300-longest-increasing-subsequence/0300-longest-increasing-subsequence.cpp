class Solution {
public:
    vector<int> nums;
    int dp[2501];
    int f(int i,int prev_ind){
        if(i==nums.size()) return 0;
        
        int &d=dp[prev_ind+1];
        if(d!=-1) return d;
        int len=f(i+1,prev_ind);
        if(prev_ind==-1 || nums[i]>nums[prev_ind]){
            len=max(len,1+f(i+1,i));
        }
        return d=len;
    }
    int lengthOfLIS(vector<int>& arr) {
        memset(dp,-1,sizeof(dp));
        nums=arr;
        return f(0,-1);
    }
};