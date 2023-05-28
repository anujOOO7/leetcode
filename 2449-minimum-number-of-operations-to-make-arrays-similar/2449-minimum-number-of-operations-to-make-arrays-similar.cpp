class Solution {
public:
    long long makeSimilar(vector<int>& nums, vector<int>& target) {
        vector<int> e1,e2,o1,o2;
        sort(nums.begin(),nums.end());
        sort(target.begin(),target.end());
        for(auto i:nums){
            if(i&1) o1.push_back(i);
            else e1.push_back(i);
        }
        for(auto i:target){
            if(i&1) o2.push_back(i);
            else e2.push_back(i);
        }
        long long s=0;
        for(int i=0;i<o1.size();i++) s+=abs(o1[i]-o2[i]);
        for(int i=0;i<e1.size();i++) s+=abs(e1[i]-e2[i]);
        return s/4;
    }
};