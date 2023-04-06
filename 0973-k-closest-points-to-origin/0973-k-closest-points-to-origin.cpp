bool cmp(pair<int,pair<int,int>> &a,pair<int,pair<int,int>> &b){
    long double x,y;
    x=sqrt(a.second.first*a.second.first+a.second.second*a.second.second);
    y=sqrt(b.second.first*b.second.first+b.second.second*b.second.second);
    return x<y;
}

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k){
        vector<vector<int>> ans;
        vector<pair<int,pair<int,int>>> v;
        int ind=0;
        for(auto i:points)
        {
            v.push_back({ind,{i[0],i[1]}});
            ind++;
        }
        sort(v.begin(),v.end(),cmp);
        for(auto i:v)
        {
            --k;
            ans.push_back(points[i.first]);
            if(k<=0) break;
        }
        return ans;
    }
};