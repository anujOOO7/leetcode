class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> ans;
        int a,b,c;
        priority_queue<tuple<int,int,int>> pq;
            for(int i=0;i<nums1.size();i++){
                for(int j=0;j<nums2.size();j++){
                    int sum=nums1[i]+nums2[j];
                    
                    if(pq.size()<k) pq.push({sum,nums1[i],nums2[j]});
                    else{
                        tie(a,b,c)=pq.top();
                        if(sum<a) {
                            pq.pop();
                            pq.push({sum,nums1[i],nums2[j]});
                        }
                        else break;
                    }
                    
                }
            }

        while(!pq.empty()){
            tie(a,b,c)=pq.top();
            ans.push_back({b,c});
            pq.pop();
        }
        return ans;
    }
};