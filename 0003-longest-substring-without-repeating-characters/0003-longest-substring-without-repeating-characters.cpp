class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char,int> m;
        int i=0,j=0,ans=0;
        while(i<s.length()){
            m[s[i]]++;
            if(m.size()==i-j+1)
                ans=max(ans,i-j+1);
            while(m.size()<i-j+1){
                if(m[s[j]]==1)
                    m.erase(s[j]);
                else
                    m[s[j]]--;
                j++;
            }
            i++;
        }
        return ans;
    }
};