class Solution {
public:
    int numberOfSubstrings(string s) {
        int i=0,j=0,count=0;
        unordered_map<int,int> mp;
        while(j<s.length()){
            mp[s[j]]++;
            if(mp.size()==3){
                while(mp.size()==3){
                    count+=s.length()-j;
                    mp[s[i]]--;
                    if(mp[s[i]]==0){
                        mp.erase(s[i]);
                    }
                    i++;
                }
            }
            j++;
        }
        return count;
    }
};