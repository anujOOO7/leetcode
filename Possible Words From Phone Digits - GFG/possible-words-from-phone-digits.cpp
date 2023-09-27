//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
#include <string>

using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    vector<string> ans;
    vector<string> v{"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    void f(int i,int a[],int n,string &temp){
        if(i==n){
            ans.push_back(temp);
            return;
        }
        
        for(int j=0;j<v[a[i]].length();j++){
            temp.push_back(v[a[i]][j]);
            f(i+1,a,n,temp);
            temp.pop_back();
        }
    }
    //Function to find list of all words possible by pressing given numbers.
    vector<string> possibleWords(int a[], int N)
    {
        string temp;
        f(0,a,N,temp);
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
  
	int T;
	
	cin >> T; //testcases
	
	while(T--){ //while testcases exist
	   int N;
	    
	   cin >> N; //input size of array
	   
	   int a[N]; //declare the array
	   
	   for(int i =0;i<N;i++){
	       cin >> a[i]; //input the elements of array that are keys to be pressed
	   }
	   
	   Solution obj;
	   
	  vector <string> res = obj.possibleWords(a,N);
	  for (string i : res) cout << i << " ";
	   cout << endl;
	}
	
	return 0;
}
// } Driver Code Ends