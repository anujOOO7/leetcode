class Solution {
public:
    string s;
    set<string> d;
    int dp[301];
    bool f(int i){
        if(i==s.length()) return true;
        
        if(dp[i]!=-1) return dp[i];
        for(int j=i;j<=s.length();j++){
            if(d.count(s.substr(i,j-i+1)) && f(j+1)){
                return dp[i]=true;
            }
        }
        return dp[i]=false;
    }
    bool wordBreak(string S, vector<string>& wordDict) {
        set<string> dict(wordDict.begin(),wordDict.end());
        s=S,d=dict;
        memset(dp,-1,sizeof(dp));
        return f(0);
    }
};