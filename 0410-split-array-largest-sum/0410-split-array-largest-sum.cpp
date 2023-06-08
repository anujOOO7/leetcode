class Solution {
public:
    vector<int> nums;
    int dp[1001][51];
    int f(int i,int m){
        if(i==size(nums)){
            if(m==0) return 0;
            return 1e9;
        }
        if(m<=0) return 1e9;
        
        int &d=dp[i][m];
        if(d!=-1) return d;
        int ans=1e9,sum=0;
        for(int j=i;j<size(nums);j++){
            sum+=nums[j];
            ans=min(ans,max(sum,f(j+1,m-1)));
        }
        return d=ans;
    }
    int splitArray(vector<int>& arr, int k) {
        nums=arr;
        memset(dp,-1,sizeof(dp));
        return f(0,k);
    }
};