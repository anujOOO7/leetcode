//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
# define mod 1000000007

// } Driver Code Ends
class Solution{
    public:
    //You need to complete this fucntion
    using ll=long long;
    ll modExpo(ll x, ll n, ll m)
    {
        ll res = 1;
        while (n > 0)
        {
            if (n & 1)
            {
                res = res * x % m;
                n--;
            }
            else
            {
                x = x * x % m;
                n /= 2;
            }
        }
        return res;
    }
    ll power(int N,int R)
    {
       ll k=N,num=0;
       while(k){
           num=(num*10)+(k%10);
           k/=10;
       }
       return modExpo(N,num,1e9+7);
    }
};

//{ Driver Code Starts.

// compute reverse of a number 
long long rev(long long n)
{
    long long rev_num = 0;
     while(n > 0) 
      { 
        rev_num = rev_num*10 + n%10; 
        n = n/10; 
      } 
      return rev_num;
}




int main()
{
    int T;
    cin>>T;//testcases
    
    while(T--)
    {
        long long N;
        cin>>N;//input N
        
        long long R = 0; 
        
        // reverse the given number n
        R = rev(N);
        Solution ob;
        //power of the number to it's reverse
        long long ans =ob.power(N,R);
        cout << ans<<endl;
    }
}
// } Driver Code Ends