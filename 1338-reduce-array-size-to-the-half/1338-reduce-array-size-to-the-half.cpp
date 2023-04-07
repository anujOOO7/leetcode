class Solution {
public:
    int minSetSize(vector<int>& arr) {
        map<int,int> m;
        priority_queue<pair<int,int>> pq;
        int ans=0,sum=0;
        for(auto ch:arr) m[ch]++;
        for(auto [x,y]:m){
            pq.push({y,x});
        }
        while(!pq.empty()){
            auto i=pq.top();
            sum+=i.first;
            ans++;
            if(sum>=arr.size()/2) return ans;
            pq.pop();
        }
        return ans;
    }
};