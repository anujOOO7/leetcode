class Solution {
public:
    int n,cnt=0;
    map<int,int> m;
    void dfs(int i,vector<vector<int>>& rooms){
        m[i]++;
        for(auto it:rooms[i]){
            if(!m[it]) dfs(it,rooms);
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        n=size(rooms);
        m[0]++;
        dfs(0,rooms);
        for(int i=0;i<n;i++){
            if(m[i]==0) return false;
        }
        return true;
    }
};