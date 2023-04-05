class Solution {
public:
    int a[40];
    int f(int n){
        if(n==0) return 0;
        if(n==1) return 1;
        if(a[n]!=-1) return a[n];
        return a[n]=f(n-1)+f(n-2);
    }
    
    int fib(int n) {
        memset(a,-1,sizeof(a));
        return f(n);
    }
};