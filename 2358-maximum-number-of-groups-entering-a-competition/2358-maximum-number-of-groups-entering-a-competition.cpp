class Solution
{
public:
    typedef long long ll;
    bool check(ll mid,ll n){
        return (mid*(mid+1)/2)<=n;
    }
                
    int maximumGroups(vector<int> &grades)
    {
        int n = grades.size(),l(0),r(1e6),mid;
        while(r-l>1){
            mid=(l+r)/2;
            if(check(mid,n))
                l=mid;
            else
                r=mid;
        }
        return l;
    }
};