class Solution {
public:
    string predictPartyVictory(string s) {
        int r=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='R'){
                if(r<0) s.push_back('D');
                r++;
            }
            else{
                if(r>0) s.push_back('R');
                r--;
            }
        }
        return r>0?"Radiant":"Dire";
    }
};