class Solution {
public:
    int characterReplacement(string s, int k) {
        map<char,int> m;
        int i=0,j=0,ans=0,res=0;
        while(i<s.length()){
            m[s[i]]++;
            ans=max(ans,m[s[i]]);
            while(i-j+1-ans>k){
                m[s[j]]--;
                j++;
            }
            res=max(res,i-j+1);
            i++;
        }
        return res;
    }
};