class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int l=-1,r=arr.size();
        while(r-l>1) {
            int mid=(l+r)/2;
            if(arr[mid]-mid>k)
                r=mid;
            else
                l=mid;
        }
        return r+k;
    }
};