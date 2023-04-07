class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        set<int> s;
        for(auto val:nums) s.insert(val);
        int k=1;
        for(auto num:s){
            if(num<=0) continue;
            else{
                if(num!=k)
                    return k;
                else k++;
            }
        }
        return k;
    }
};