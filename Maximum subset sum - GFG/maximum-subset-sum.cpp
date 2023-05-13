//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class IntArray
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends
class Solution {

  public:
    int dp[2][100001];
    long long fun(vector<int>&A, int N, bool check, int x)
    {
        // false -> dono le skte hai
        if(x==N)return 0;
        
        if(dp[check][x]!=-1)return dp[check][x];
        
        if(check==false)
            return dp[check][x]= max(A[x]+fun(A, N, false, x+1), fun(A, N, true, x+1));
        else
            return dp[check][x]= A[x]+ fun(A, N, false, x+1);
        
    }
    long long findMaxSubsetSum(int N, vector<int> &A) {
        // code here
        memset(dp, -1, sizeof(dp));
        return fun(A, N, false, 0);
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        vector<int> A(N);
        IntArray::input(A,N);
        
        Solution obj;
        long long res = obj.findMaxSubsetSum(N, A);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends