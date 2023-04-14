class Solution {
public:
    int countDistinctIntegers(vector<int>& nums) {
        set<int> s(nums.begin(),nums.end());
        for(auto i:nums){
            int num=0;
            while(i){
                int rem=i%10;
                num=num*10+rem;
                i/=10;
            }
            s.insert(num);
        }
        return s.size();
    }
};