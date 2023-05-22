class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> m;
        for(auto val:nums) m[val]++;
        vector<pair<int,int>> v;
        for(auto [x,y]:m) v.push_back({x,y});
        sort(v.begin(),v.end(),[&](pair<int,int> &a,pair<int,int> &b){
            return a.second>b.second;
        });
        vector<int> ans;
        for(int i=0;i<k;i++) ans.push_back(v[i].first);
        return ans;
    }
};