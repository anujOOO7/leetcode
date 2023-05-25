class Solution {
public:
    int n,m;
    string s,t;
    int numDistinct(string str1, string str2) {
        s=str1,t=str2;
        n=s.size(),m=t.size();
        
        vector<double> dp(m+1,0);
        dp[0]=1;
        
        for(int i=1;i<=n;i++){
            for(int j=m;j>=1;j--){
                if(s[i-1]==t[j-1]) dp[j]=dp[j-1]+dp[j];
            }
        }
        return (int)dp[m];
    }
};