class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& v) {
        vector<vector<int>> ans;
        sort(v.begin(),v.end());
        int n=v.size(),start,end;
        for(int i=0;i<n-1;i++)
        {
            start=v[i][0];
            end=v[i][1];
            while(i<n-1 && end>=v[i+1][0]){
                end=max(end,v[i+1][1]);
                i++;
            }
            ans.push_back({start,end});
        }
        if(end<v[n-1][1])
            ans.push_back({v[n-1][0],v[n-1][1]});
        return ans;
    }
};