bool cmp(pair<int,int> &a,pair<int,int> &b){
    if(a.first==b.first)
        return a.second>b.second;
    return a.first>b.first;
}
class Solution {
public:
    vector<int> getStrongest(vector<int>& arr, int k) {
        vector<int> ans;
        sort(arr.begin(),arr.end());
        int median=arr[(arr.size()-1)/2];
        
        vector<pair<int,int>> v;
        for(int i=0;i<arr.size();i++){
            v.push_back({abs(arr[i]-median),arr[i]});
        }
        
        sort(v.begin(),v.end(),cmp);
        for(int i=0;i<k;i++)
            ans.push_back(v[i].second);
        return ans;
    }
};