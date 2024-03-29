//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    vector<int> ans;
    void f(int ind,int sum,vector<int>& arr,vector<int>& freq){
        if(ind>=arr.size()) return;
        
        for(int i=ind;i<arr.size();i++){
            if(freq[i]==0){
                sum+=arr[i];
                ans.push_back(sum);
                f(i+1,sum,arr,freq);
                
                freq[i]=0;
                sum-=arr[i];
            }
        }
    }
    vector<int> subsetSums(vector<int> arr, int N)
    {
        vector<int> freq(N,0);
        ans.push_back(0);
        f(0,0,arr,freq);
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