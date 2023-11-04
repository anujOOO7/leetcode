//{ Driver Code Starts
//Initial template for c++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++
#include<bits/stdc++.h> 

class Solution{   
public:
    int minimumStep(int n){
        //complete the function here
        // vector<int> adj[n+1];
        // for(int i=1;i<=n;i++){
        //     if(3*i<=n) adj[i].push_back(3*i);
        //     adj[i].push_back(i+1);
        // }
        
        // vector<int> dist(n+1,INT_MAX);
        // using pi=pair<int,int>;
        // priority_queue<pi,vector<pi>,greater<pi>> pq;
        // pq.push({0,1});
        // dist[1]=0;
        
        // while(!pq.empty()){
        //     auto x=pq.top();
        //     int node=x.second;
        //     int cost=x.first;
        //     pq.pop();
            
        //     if(node==n) return cost;
        //     for(int nbr:adj[node]){
        //         if(dist[nbr]>cost+1){
        //             dist[nbr]=dist[node]+1;
        //             pq.push({dist[nbr],nbr});
        //         }
        //     }
        // }
        // return -1;
        
        int ans=0;
        while(n){
            if(n%3==0){
                n/=3;
                ans++;
            }
            else{
                n--;
                ans++;
            }
        }
        return ans-1;
    }
};


//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.minimumStep(n) << endl;
    
    }
    return 0; 
} 


// } Driver Code Ends