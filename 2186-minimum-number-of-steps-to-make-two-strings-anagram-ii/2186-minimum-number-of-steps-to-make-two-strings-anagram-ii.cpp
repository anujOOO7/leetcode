class Solution {
public:
    int minSteps(string s, string t) {
        map<char,int> m;
        for(auto c:s) m[c]++;
        int count=0;
        for(auto c:t){
            if(m[c]) m[c]--;
            else count++;
            if(m[c]==0) m.erase(c);
        }
        for(auto [x,y]:m) count+=y;
        return count;
    }
};