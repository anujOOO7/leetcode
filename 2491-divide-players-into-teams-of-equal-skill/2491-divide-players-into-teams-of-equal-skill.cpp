class Solution {
public:
    long long dividePlayers(vector<int>& s) {
        using ll=long long;
        sort(begin(s),end(s));
        int n=s.size();
        ll sum=0,c=s[0]+s[n-1];
        for(int i=0;i<n/2;i++){
            if(s[i]+s[n-i-1]!=c) return -1;
            else sum+=(s[i]*s[n-i-1]);
        }
        return sum;
    }
};