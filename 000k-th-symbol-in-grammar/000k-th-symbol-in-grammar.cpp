class Solution {
public:
    int gen(int n,int k){
        if(n==1 && k==1)
            return 0;
        
        int mid=pow(2,n-1)/2;
        if(k<=mid)
            return gen(n-1,k);
        return !gen(n-1,k-mid);
    }
    
    int kthGrammar(int n, int k) {
        return gen(n,k);
    }
};