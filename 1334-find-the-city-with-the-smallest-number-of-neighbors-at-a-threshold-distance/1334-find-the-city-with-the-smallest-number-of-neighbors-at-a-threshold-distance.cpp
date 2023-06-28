class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int dt) {
        vector<vector<int>> dist(n,vector<int>(n,1e9));
        //creating the distance matrix
        for(auto it:edges){
            int u=it[0],v=it[1],wt=it[2];
            dist[u][v]=dist[v][u]=wt;
        }
        
        for(int i=0;i<n;i++){
            dist[i][i]=0;
        }
        
        //floyd warshall algo
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
                }
            }
        }
        
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++){
        //         cout<<dist[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        
        int ans=INT_MAX,ind;
        for(int i=0;i<n;i++){
            int cnt=0;
            for(int j=0;j<n;j++){
                if(dist[i][j]<=dt) cnt++;
            }
            if(cnt<=ans){
                ans=cnt;
                ind=i;
            } 
        }
        return ind;
    }
};