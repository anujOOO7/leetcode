class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int m=mat.size(),n=mat[0].size();
        int l=0,r=m*n-1;
        
        while(l<=r){
            int mid=(l+r)/2;
            if(mat[mid/n][mid%n]==target)
                return true;
            else if(mat[mid/n][mid%n]>target)
                r=mid-1;
            else
                l=mid+1;
        }
        return false;
    }
};