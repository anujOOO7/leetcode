class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n=size(nums);
        if(n==1) return 1;
        auto mnInd=min_element(begin(nums),end(nums))-begin(nums)+1;
        auto mxInd=max_element(begin(nums),end(nums))-begin(nums)+1;
        if(mnInd>mxInd) swap(mnInd,mxInd);
        int ans=min(mxInd,min(n-mnInd+1,mnInd+n-mxInd+1));
        return ans;
    }
};