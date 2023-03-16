class Solution {
public:
    #define mod 1000000007
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        long long sum;
        vector<int> v;
        for(int i=0;i<n;i++){
            v.push_back(nums[i]);
            sum=nums[i];
            for(int j=i+1;j<n;j++){
                sum+=nums[j];
                v.push_back(sum);
            }
        }
        sort(v.begin(),v.end());
        long long s=0;
        for(int i=left-1;i<right;i++)
        {
            s+=v[i];
            s%=mod;
        }
        return s;
    }
};