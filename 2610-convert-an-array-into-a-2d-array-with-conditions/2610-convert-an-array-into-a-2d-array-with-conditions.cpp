class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        map<int,int> m;
        int mx=0;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
            mx=max(mx,m[nums[i]]);
        }
        vector<vector<int>> ans(mx);
        for(auto [x,y]:m){
            for(int i=0;i<y;i++){
                ans[i].push_back(x);
            }
        }
        return ans;
    }
};