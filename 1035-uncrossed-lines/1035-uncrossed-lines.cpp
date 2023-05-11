class Solution {
public:
    int dp[501][501];
    int f(vector<int>& nums1,vector<int>& nums2,int i,int j){
        if(i>=nums1.size() || j>=nums2.size()) return 0;
        
        if(dp[i][j]!=-1) return dp[i][j];
        if(nums1[i]==nums2[j]) return dp[i][j]=1+f(nums1,nums2,i+1,j+1);
        else return dp[i][j]=max(f(nums1,nums2,i,j+1),f(nums1,nums2,i+1,j));
    }
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        memset(dp,-1,sizeof(dp));
        return f(nums1,nums2,0,0);
    }
};