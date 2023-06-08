class Solution {
public:
    int dp[2001];
    bool isPalindrome(string &s,int i,int j){
        while(i<=j){
            if(s[i++]!=s[j--]) return false;
        }
        return true;
    }
    
    int f(int ind,string s){
        if(ind==s.size()) return -1;
        
        int &d=dp[ind];
        if(d!=-1) return d;
        int ans=INT_MAX;
        for(int i=ind;i<s.size();i++){
            //if s.substr(ind,i-ind+1) is palindrome then move for next steps
            if(isPalindrome(s,ind,i)){
                ans=min(ans,1+f(i+1,s));
            }
        }
        return d=ans;
    }
    
    int minCut(string s) {
        memset(dp,-1,sizeof(dp));
        return f(0,s);
    }
};