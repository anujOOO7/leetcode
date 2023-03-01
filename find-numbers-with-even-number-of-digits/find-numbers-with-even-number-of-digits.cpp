class Solution {
public:
    bool check(int n){
        int count=0;
        while(n){
            count++;
            n/=10;
        }
        return count%2==0;
    }
    
    int findNumbers(vector<int>& nums) {
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            if(check(nums[i]))
                cnt++;
        }
        return cnt;
    }
};