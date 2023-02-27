class Solution {
public:
    int a[46];
    int f(int n){
        if(n==0||n==1)
            return 1;
        if(a[n]!=-1) 
            return a[n];
        return a[n]=f(n-1)+f(n-2);
    }
    
    int climbStairs(int n) {
        memset(a,-1,sizeof(a));
        return f(n);
    }
};