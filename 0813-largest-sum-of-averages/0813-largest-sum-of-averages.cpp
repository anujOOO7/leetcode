class Solution {
public:
    vector<vector<double>> dp;
    vector<int> nums,a;
    double f(int i,int j,int div){
        if(i>j) return 0.0;
        if(div==0) return (double(a[j]-a[i-1]))/double(j-i+1);
        
        double &d=dp[i][div];
        if(d!=-1) return d;
        double sum=0;
        for(int k=i;k<=j;k++){
            double temp=(double(a[k]-a[i-1]))/double(k-i+1)+f(k+1,j,div-1);
            sum=max(sum,temp);
        }
        return d=sum;
    }
    double largestSumOfAverages(vector<int>& arr, int k) {
        vector<int> p(arr.size()+1,0);
        for(int i=0;i<arr.size();i++) p[i+1]=arr[i]+p[i];
        a=p,nums=arr;
        dp.resize(nums.size()+1,vector<double>(k,-1));
        return f(1,nums.size(),k-1);
    }
};