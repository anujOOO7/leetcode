class Solution {
public:
    int dp[101];
    int f(int i,string s){
        if(i==s.length()) return 1;
        
        if(dp[i]!=-1) return dp[i];
        int ans=0;
        for(int j=i;j<min(i+2,(int)s.length());j++){
            string tmp=s.substr(i,j-i+1);
            if(tmp[0]=='0') continue;
            int k=stoi(tmp);
            if(k<=26 && k>=1) ans+=f(j+1,s);
        }
        return dp[i]=ans;
    }
    int numDecodings(string s) {
        memset(dp,-1,sizeof(dp));
        return f(0,s);
    }
};