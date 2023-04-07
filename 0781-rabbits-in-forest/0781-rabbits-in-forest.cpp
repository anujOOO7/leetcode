class Solution {
public:
    int numRabbits(vector<int>& answers) {
        map<int,int> m;
        for(auto i:answers) m[i]++;
        int count=0;
        for(auto [x,y]:m){
            count+=((x+y)/(x+1))*(x+1);
        }
        return count;
    }
};