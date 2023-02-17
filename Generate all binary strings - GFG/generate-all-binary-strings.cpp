//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:

    void generateBinaryStrings(int& num){
        //Write your code
        binaryString(num,"");
    }
    
    void binaryString(int &num,string s){
        if(s.length()==num){
            cout<<s<<" ";
            return ;
        }
        
        binaryString(num,s+"0");
        
        if (s.length() == 0 || s[s.length() - 1] != '1')
        {
            binaryString(num, s + "1");
        }
    }
};

//{ Driver Code Starts.
int main(){
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while(t--){
        //Input
        int n; cin >> n;

        Solution obj;
        // cout << setprecision(9) << obj.switchCase(choice,vec) << endl;
        obj.generateBinaryStrings(n);
        cout << endl;
        
        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}

// } Driver Code Ends