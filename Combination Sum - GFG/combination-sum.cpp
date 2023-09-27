//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
  public:
    //Function to return a list of indexes denoting the required 
    //combinations whose sum is equal to given number.
    vector<vector<int>> ans;
    set<vector<int>> s;
    void f(int i,vector<int>& a,int target,vector<int> &temp){
        if(target==0){
            s.insert(temp);
            return;
        }
        if(i==a.size()) return;
        
        if(target>=a[i])
        {
            temp.push_back(a[i]);
            f(i,a,target-a[i],temp);
            temp.pop_back();
        }
        while(i+1<a.size() && a[i]==a[i+1]) i++;
        f(i+1,a,target,temp);
    }
    vector<vector<int> > combinationSum(vector<int> &A, int B) {
        vector<int> temp;
        sort(A.begin(),A.end());
        f(0,A,B,temp);
        for(auto i:s) ans.push_back(i);
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            A.push_back(x);
        }   
        int sum;
        cin>>sum;
        Solution ob;
        vector<vector<int>> result = ob.combinationSum(A, sum);
   		if(result.size()==0){
   			cout<<"Empty";
   		}
        for(int i=0;i<result.size();i++){
            cout<<'(';
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j];
                if(j<result[i].size()-1)
                    cout<<" ";
            }
            cout<<")";
        }
        cout<<"\n";
    }
}	
// } Driver Code Ends