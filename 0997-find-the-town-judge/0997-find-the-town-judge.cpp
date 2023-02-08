class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        map<int,int> a,b;
        for(auto it:trust){
            a[it[0]]++;
            b[it[1]]++;
        }
        
        for(int i=1;i<=n;i++){
            if(a[i]==0 && b[i]==n-1)
                return i;
        }
        return -1;
    }
};