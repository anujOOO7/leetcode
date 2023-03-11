class Solution {
public:
    int singleNumber(vector<int>& nums) {
        map<int,int> m;
        for(auto val:nums){
            m[val]++;
        }
        for(auto it:m){
            if(it.second!=3)
                return it.first;
        }
        return 0;
    }
};