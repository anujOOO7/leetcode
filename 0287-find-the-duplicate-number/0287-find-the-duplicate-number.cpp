class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        bool marked[100001];
        memset(marked,false,sizeof(marked));
        for(int i=0;i<nums.size();i++){
            if(marked[nums[i]])
                return nums[i];
            marked[nums[i]]=true;
        }
        return 0;
    }
};