class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        map<int,int> m;
        queue<int> q;
        q.push(0);
        
        while(!q.empty()){
            int x=q.front();
            q.pop();
            
            if(!m[x]){
                m[x]++;
                for(auto it:rooms[x]){
                    q.push(it);
                }
            }
        }
        for(int i=0;i<rooms.size();i++){
            if(!m[i]) return false;
        }
        return true;
    }
};