int nextNumber(int n)
{
    int num=0;
    while(n!=0){
        num+=(n%10)*(n%10);
        n=n/10;
    }
    return num;
}

class Solution {
public:    
    bool isHappy(int n) {
        set<int> set;
        while(n!=1 && !set.count(n))
        {
            set.insert(n);
            n=nextNumber(n);
        }
        return n==1;
    }
};