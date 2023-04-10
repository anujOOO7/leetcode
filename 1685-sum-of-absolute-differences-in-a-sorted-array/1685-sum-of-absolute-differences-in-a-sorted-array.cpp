class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n=nums.size();
        vector<int> pre(n),ans(n);
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            pre[i]=sum;
        }
        
        for(int i=0;i<n;i++){
            ans[i]=((pre[n-1]-pre[i])-nums[i]*(n-i-1))+(nums[i]*(i+1)-pre[i]);
        }
        return ans;
    }
};