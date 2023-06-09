class Solution {
public:
    int dp[601][101][101];
    int count0(string s){
        int cnt0=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='0') cnt0++;
        }
        return cnt0;
    }
    
    int f(int i,vector<string>& s,int m,int n){
        if(i==s.size()) return 0;
        
        int &d=dp[i][m][n];
        if(d!=-1) return d;
        int zero=count0(s[i]);
        int ones=s[i].length()-zero;
        int take=0;
        if(m>=zero && n>=ones){
            take=1+f(i+1,s,m-zero,n-ones);
        }
        int not_take=0+f(i+1,s,m,n);
        return d=max(take,not_take);
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        memset(dp,-1,sizeof(dp));
        return f(0,strs,m,n);
    }
};