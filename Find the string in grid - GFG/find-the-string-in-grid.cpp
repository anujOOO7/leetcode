//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
int n,m,s;
    vector<int> dx={-1,-1,-1,0,1,1,1,0};
    vector<int> dc={-1,0,1,1,1,0,-1,-1};
    bool fun(int i,int j,vector<vector<char>> &grid,string &word,int ind,int dir){
        if(ind==s) return true;
        if(i>=0 && i<n && j>=0 && j<m && grid[i][j]==word[ind]){
            return fun(i+dx[dir],j+dc[dir],grid,word,ind+1,dir);
        }
        return false;
    }
public:
    vector<vector<int>>searchWord(vector<vector<char>>grid, string word){
        n=grid.size(),m=grid[0].size(),s=word.size();
        vector<vector<int>> res;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==word[0]){
                    for(int k=0;k<8;k++){
                        if(fun(i+dx[k],j+dc[k],grid,word,1,k)){
                            res.push_back({i,j});
                            break;
                        } 
                    }
                    
                }
            }
        }
        return res;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>grid(n, vector<char>(m,'x'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> grid[i][j];
		}
		string word;
		cin >> word;
		Solution obj;
		vector<vector<int>>ans = obj.searchWord(grid, word);
		if(ans.size() == 0)
		{
		    cout<<"-1\n";
		}
		else
		{
		    for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		    }
		}
		
		
	}
	return 0;
}
// } Driver Code Ends