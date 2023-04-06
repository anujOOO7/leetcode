bool cmp(pair<string,int> &a,pair<string,int> &b){
    if(a.second==b.second) return a.first<b.first;
    return a.second>b.second;
}

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string,int> mp;
        for(int i=0;i<words.size();i++){
            mp[words[i]]++;
        }
        vector<pair<string,int>> m;
        for(auto [x,y]:mp) m.push_back({x,y});
        sort(m.begin(),m.end(),cmp);
        int count=1;
        vector<string> ans;
        for(auto val:m){
            ans.push_back(val.first);
            count++;
            if(count>k) break;
        }
        return ans;
    }
};