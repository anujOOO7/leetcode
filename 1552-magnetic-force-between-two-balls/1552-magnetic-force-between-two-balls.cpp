class Solution {
public:
    bool f(int mid,vector<int>& p,int m){
        int count=0;
        int i=0;
        while(i!=p.size()){
            i=lower_bound(p.begin(),p.end(),p[i]+mid)-p.begin();
            count++;
        }
        return count>=m;
    }
    
    int maxDistance(vector<int>& p, int m) {
        sort(begin(p),end(p));
        int n=p.size();
        int l=0,r=1e9;
        while(r-l>1){
            int mid=l+(r-l)/2;
            if(f(mid,p,m)) l=mid;
            else r=mid;
        }
        return l;
    }
};