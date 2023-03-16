class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& str) {
        map<string,vector<string>> m;
        vector<vector<string>> ans;
        for(int i=0;i<str.size();i++){
            string s=str[i];
            sort(str[i].begin(),str[i].end());
            m[str[i]].push_back(s);
        }
        for(auto x:m){
            ans.push_back(x.second);
        }
        return ans;
    }
};