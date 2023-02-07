class Solution {
public:
typedef long long ll; 
    
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int l(0),i(k),r(nums.size());
        long long temp=0,ans=0;
        
        map<int,int> m;
        for(int i=0;i<k;i++){
            m[nums[i]]++;
            temp+=nums[i];
        }
        if(m.size()==k)
            ans=max(ans,temp);
        
        while(i<r){
            m[nums[l]]--;
            temp-=nums[l];
            
            if(m[nums[l]]==0)
                m.erase(nums[l]);
            l++;
            
            m[nums[i]]++;
            temp+=nums[i];
            
            if(m.size()==k)
                ans=max(ans,temp);
            i++;
        }
        return ans;
    }
};