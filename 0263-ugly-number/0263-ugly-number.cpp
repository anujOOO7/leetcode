class Solution {
public:
    bool isUgly(int n) {
        if(n<=0) return false;
        set<int> s;
        int N=n;
        for(int i=2;i<=sqrt(n);i++){
            if(N%i==0){
                while(N%i==0){
                    s.insert(i);
                    N/=i;
                }
            }
        }
        if(N>1) s.insert(N);
        for(auto val:s){
            if(val!=2 && val!=3 && val!=5) return false;
        }
        return true;
    }
};