class Solution {
public:
    string frequencySort(string s) {
        map<char,int> m;
        string ans;
        priority_queue<pair<int,char>> pq;
        for(auto ch:s) m[ch]++;
        for(auto [x,y]:m){
            pq.push({y,x});
        }
        while(!pq.empty()){
            auto i=pq.top(); pq.pop();
            for(int j=0;j<i.first;j++) ans+=i.second;
        }
        return ans;
    }
};