class Solution {
public:
    bool f(vector<int>& dist,double mid,int n,double hour){
        double sum=0;
        for(int i=0;i<n;i++){
            sum+=ceil(dist[i]/mid);
        }
        return sum+(dist[n]/mid)<=hour;
    }
    
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int d=dist.size();
        int l=0,r=INT_MAX;
        while(r-l>1){
            double mid=l+(r-l)/2;
            if(f(dist,mid,d-1,hour)) r=mid;
            else l=mid;
        }
        cout<<r<<" "<<l<<endl;
        if(r==INT_MAX) return -1;
        return r;
    }
};