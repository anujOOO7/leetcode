class Solution {
public:
    bool check(vector<int>& a,long long mid,int k){
        int i=0,count=0;
        while(i<a.size()){
            i=lower_bound(a.begin(),a.end(),a[i]+mid)-a.begin();
            count++;
            if(count>=k)
                break;
        }
        return count>=k;
    }
    
    int maximumTastiness(vector<int>& price, int k) {
        sort(price.begin(),price.end());
        int n=price.size(),ans;
        long long l=0,r=price[n-1]-price[0];
        while(r>=l){
            long long mid=(l+r)/2;
            if(check(price,mid,k)){
                ans=mid;
                l=mid+1;
            }
            else
                r=mid-1;
        }
        return ans;
    }
};