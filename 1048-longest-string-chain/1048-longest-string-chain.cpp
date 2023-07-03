class Solution {
public:
    int dp[1001];
    bool check(string a,string b){
        int i=0,j=0;
        if(a.length()!=b.length()-1) return false;
        while(j<b.length()){
            if(a[i]==b[j]){
                i++; j++;
            }
            else{
                j++;
            }
        }
        if(i==a.length() && j==b.length()) return true;
        return false;
    }
    
    int f(int i,vector<string>& words){
        if(i==words.size()) return 0;
        
        if(dp[i]!=-1) return dp[i];
        int ans=0;
        
        for(int j=i+1;j<words.size();j++){
            if(words[j].length()==words[i].length()+1 && check(words[i],words[j])){
                ans=max(ans,1+f(j,words));
            }
        }
        return dp[i]=ans;
    }
    
    int longestStrChain(vector<string>& words) {
        memset(dp,-1,sizeof(dp));
        sort(words.begin(),words.end(),[&](string &a,string &b){
            return a.length()<b.length();
        });
        int ans=INT_MIN;
        for(int i=0;i<words.size();i++){
            ans=max(ans,1+f(i,words));
        }
        return ans;
    }
};