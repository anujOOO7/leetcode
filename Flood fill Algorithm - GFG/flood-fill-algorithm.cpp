//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    vector<vector<int>> moves{{-1,0},{1,0},{0,-1},{0,1}};
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int m=image.size(),n=image[0].size();
        queue<pair<int,int>> q;
        int oldColor=image[sr][sc];
        image[sr][sc]=newColor;
        q.push({sr,sc});
        
        while(!q.empty()){
            auto node=q.front();
            int r=node.first;
            int c=node.second;
            q.pop();
            
            for(int i=0;i<4;i++){
                int ni=r+moves[i][0];
                int nj=c+moves[i][1];
                
                if(ni<0 || ni>=m || nj<0 || nj>=n || 
                            image[ni][nj]!=oldColor || image[ni][nj]==newColor) continue;
                
                image[ni][nj]=newColor;
                q.push({ni,nj});
            }
        }
        return image;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends