//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends

class Solution{
    public:
    //Complete this function
    //Function to sort the array according to frequency of elements.
    vector<int> sortByFreq(int arr[],int n)
    {
        unordered_map<int,int> m;
        for(int i=0;i<n;i++) m[arr[i]]++;
        set<pair<int,int>> s;
        
        for(auto x:m) s.insert({x.second,-x.first});
            
        vector<int> v;
        for(auto x=s.rbegin(); x!=s.rend(); x++){
            auto node = *x;
            int val = node.first;
            while(val--) v.push_back(-node.second);
        }
        return v;
    }
};

//{ Driver Code Starts.

int main() {
	
	
	int t;
	cin >> t;
	
	
	while(t--){
	    
	    
	    int n;
	    cin >> n;
	    
	    int a[n+1];
	    
	    for(int i = 0;i<n;i++){
	        cin >> a[i];
	    }
	    Solution obj;
	    vector<int> v;
	    v = obj.sortByFreq(a,n);
	    for(int i:v)
	        cout<<i<<" ";
	    cout << endl;
	}
	
	return 0;
}


// } Driver Code Ends