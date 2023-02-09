class Solution {
public:
    void sortColors(vector<int>& nums) {
       int ones(0),twos(0),zeroes(0);
       for(int i=0;i<nums.size();i++)
       {
           if(nums[i]==0)
               zeroes++;
           else if(nums[i]==1)
               ones++;
           else
               twos++;
       }
        
        nums.clear();
        for(int i=0;i<zeroes;i++)
            nums.push_back(0);
        for(int i=0;i<ones;i++)
            nums.push_back(1);
        for(int i=0;i<twos;i++)
            nums.push_back(2);
    }
};