class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int mx=INT_MIN,curMul=1;
        for(int i=0;i<n;i++){
            curMul*=nums[i]; 
            mx=max(mx,curMul);
            if(curMul==0)
                curMul=1;
        }
        curMul=1;
        for(int i=n-1;i>=0;i--){
            curMul*=nums[i]; 
            mx=max(mx,curMul);
            if(curMul==0)
                curMul=1;
        } 
        return mx;
    }
};