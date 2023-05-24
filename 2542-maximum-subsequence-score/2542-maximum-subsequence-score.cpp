class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int,int>> v;
        int n=nums1.size();
        for(int i=0;i<n;i++) v.push_back({nums2[i],nums1[i]});
        sort(v.rbegin(),v.rend());

        long long ans=0,cur=0;
        priority_queue<int,vector<int>,greater<int>> pq;

        for(int i=0;i<k-1;i++){
            cur+=v[i].second;
            pq.push(v[i].second);
        }

        for(int i=k-1;i<nums1.size();i++){
            cur+=v[i].second;
            pq.push(v[i].second);
            ans=max(ans,cur*v[i].first);

            cur-=pq.top();
            pq.pop();
        } 
        return ans;
    }
};