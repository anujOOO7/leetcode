class Solution {
public:
    using ll=long long;
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        ll ans=0;
        map<int,int> m;
        for(auto i:roads){
            m[i[0]]++;
            m[i[1]]++;
        }
        priority_queue<pair<int,int>> pq;
        for(auto [x,y]:m) pq.push({y,x});
        
        map<int,int> val;
        while(pq.size()){
            val[pq.top().second]=n;
            pq.pop(); n--;
        }
        for(auto [x,y]:m) ans+=1LL*val[x]*y;
        return ans;
    }
};