class Solution {
public:
    bool check(vector<int>& time,long long n,long long totalTrips){
        long long sum=0;
        for(int i=0;i<time.size();i++){
            sum+=(n/time[i]);
        }
        return sum>=totalTrips;
    }
    
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long l=-1,r=1e14,mid;
        while(r-l>1){
            mid=(l+r)/2;
            if(check(time,mid,totalTrips)){
                r=mid;
            }
            else{
                l=mid;
            }
        }
        return r;
    }
};