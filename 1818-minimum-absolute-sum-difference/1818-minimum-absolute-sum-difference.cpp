class Solution {
public:
    int minAbsoluteSumDiff(vector<int>& nums2, vector<int>& nums1) {
        long long mod=1e9+7;
        vector<int> v=nums2;
        sort(v.begin(),v.end());
        long long sum=0,n=nums1.size();
        for(int i=0;i<nums1.size();i++) sum+=abs(nums1[i]-nums2[i]);
        
        long long res=sum;
        for(int i=0;i<n;i++)
        {
            long long tmp=sum-abs(nums1[i]-nums2[i]);
            auto ind=lower_bound(v.begin(),v.end(),nums1[i])-v.begin();
            
            if(ind!=n) res=min(res,tmp+v[ind]-nums1[i]);
            if(ind>0) res=min(res,tmp+nums1[i]-v[ind-1]);
        }
        return (int)(res%mod);
    }
};