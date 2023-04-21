class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        map<int,int> m1,m2;
        vector<int> ans;
        for(auto val:nums1) m1[val]++;
        for(auto val:nums2) m2[val]++;
        for(auto [x,y]:m1){
            for(int i=0;i<min(m1[x],m2[x]);i++)
                ans.push_back(x);
        }
        return ans;
    }
};