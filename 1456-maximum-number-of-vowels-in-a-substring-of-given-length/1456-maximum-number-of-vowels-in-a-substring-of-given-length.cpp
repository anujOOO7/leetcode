class Solution {
public:
    int maxVowels(string s, int k) {
        int cnt=0;
        set<char> t={'a','e','i','o','u'};
        for(int i=0;i<k;i++){
            if(t.count(s[i]))
                cnt++;
        }
        
        int mx=cnt;
        for(int i=k;i<s.length();i++){
            if(t.count(s[i-k]))
                cnt--;
            if(t.count(s[i]))
                cnt++;
            mx=max(mx,cnt);
        }
        return mx;
    }
};