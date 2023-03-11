//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    vector<int> ans;
    void gen(vector<int> &arr,int N,int i,vector<int> &s){
        if(i==N){
            ans.push_back(accumulate(s.begin(),s.end(),0));
            return ;
        }
        
        //not take
        gen(arr,N,i+1,s);
        
        //take
        s.push_back(arr[i]);
        gen(arr,N,i+1,s);
        s.pop_back();
    }
    
    vector<int> subsetSums(vector<int> arr, int N)
    {
        // Write Your Code here
        vector<int> s;
        gen(arr,N,0,s);
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends