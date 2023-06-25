class Solution {
public:
    int f(int count,int copied,int n){
        if(count>n || copied>n) return 1e6;
        if(count==n) return 1;
        
        return min({1+f(count+copied,copied,n),2+f(2*count,count,n)});
    }
    int minSteps(int n) {
        if(n==1) return 0;
        return f(1,1,n);
    }
};