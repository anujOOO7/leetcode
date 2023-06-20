class Solution {
public:
    using ll=long long;
    vector<int> getAverages(vector<int>& nums, int k) {
        int r=2*k+1,j=0,n=nums.size();
        ll sum=0;
        vector<int> ans(n);
        if(n<r){
            for(int i=0;i<n;i++) ans[i]=-1;
        }
        else if(k==0) return nums;
        else{
            for(int i=0;i<r;i++) sum+=nums[i];
            for(int i=0;i<n;i++){
                if(i<k) ans[i]=-1;
                else if(i==k) ans[i]=sum/r;
                else if(i+k<n){
                    sum-=nums[j];
                    sum+=nums[i+k];
                    ans[i]=sum/r;
                    j++;
                }
                else ans[i]=-1;
            }
        }
        return ans;
    }
};