class Solution {
public:
    int minSteps(string s, string t) {
        map<char,int> m;
        for(auto v:s) m[v]++;
        for(auto i:t){
            if(m[i]) m[i]--;
        }
        int count=0;
        for(auto [x,y]:m) count+=y;
        return count;
    }
};