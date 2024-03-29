class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> ans;
        priority_queue<pair<int,pair<int,int>>>pq;
        for(int i=0;i<points.size();i++)
        {
            int dis=pow(points[i][0],2)+pow(points[i][1],2);
            pq.push({dis,{points[i][0],points[i][1]}});
            if(pq.size()>k) 
            {             
                pq.pop();
            }
        }
        while(!pq.empty())
        {
            ans.push_back({pq.top().second.first,pq.top().second.second});
            pq.pop();
        }
        return ans;
    }
};