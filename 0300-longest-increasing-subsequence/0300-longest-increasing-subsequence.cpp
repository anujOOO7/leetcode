class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> cur(n+1,0),next(n+1,0);
        
        for(int i=n-1;i>=0;i--){
            for(int j=i-1;j>=-1;j--){
                int count=next[j+1];
                if(j==-1 || nums[i]>nums[j]) count=max(count,1+next[i+1]);
                cur[j+1]=count;
            }
            next=cur;
        }
        return cur[0];
    }
};