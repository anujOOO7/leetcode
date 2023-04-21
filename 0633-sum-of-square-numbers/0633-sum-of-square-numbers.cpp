class Solution {
public:
    bool judgeSquareSum(int c) {
        for(int i=sqrt(c);i>=0;i--){
            int k=c;
            k-=i*i;
            if(ceil(sqrt(k))==floor(sqrt(k))) return true;
        }
        return false;
    }
};