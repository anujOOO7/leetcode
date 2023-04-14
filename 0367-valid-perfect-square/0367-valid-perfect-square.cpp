class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num==1)
            return true;
        int i(1),j(num/2);
        while(i<=j){
            long int mid=(i+j)/2;
            if((long long)mid*mid==num)
                return true;
            if((long long)mid*mid>num)
                j=mid-1;
            else
                i=mid+1;
        }
        return false;
    }
};