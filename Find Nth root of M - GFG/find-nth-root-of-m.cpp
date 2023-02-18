//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	
	int NthRoot(int n, int m)
	{
	    // Code here.
	    int l=1,r=1e9,mid;
	    while(r-l>1){
	        mid=(l+r)/2;
	        if(pow(mid,n)==m)
	            return mid;
	        else if(pow(mid,n)<m)
	            l=mid;
	        else
	            r=mid;
	    }
	    if(pow(l,n)==m)
	        return l;
	    if(pow(r,n)==m)
	        return r;
	    return -1;
	}  
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		Solution ob;
		int ans = ob.NthRoot(n, m);
		cout << ans << "\n";
	}  
	return 0;
}
// } Driver Code Ends