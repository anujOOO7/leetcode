class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int l1=nums1.size(),l2=nums2.size();
        int ans=0;
        if(l1%2==0 && l2%2==0){
            //do nothing
        }
        else if(l1%2==0 && l2&1)
        {
            for(int i=0;i<l1;i++) ans^=nums1[i];
        }
        else if(l1&1 && l2%2==0)
        {
            for(int i=0;i<l2;i++) ans^=nums2[i];
        }
        else
        {
            for(int i=0;i<l1;i++) ans^=nums1[i];
            for(int i=0;i<l2;i++) ans^=nums2[i];
        }
        return ans;
    }
};