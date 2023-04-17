// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int l(0),r(n),mid;
        while(l<=r){
            mid=l+(r-l)/2;
            if(isBadVersion(mid)==true && isBadVersion(mid-1)==false)
                return mid;
            else if(isBadVersion(mid)==false)
                l=mid+1;
            else
                r=mid-1;
        }
        return -1;
    }
};