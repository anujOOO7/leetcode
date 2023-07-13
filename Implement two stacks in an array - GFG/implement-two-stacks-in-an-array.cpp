//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends


class twoStacks
{
    int *arr;
    int size;
    int i,j;
    public:
    
    twoStacks(int n=200)
    {
        size = n; 
        arr = new int[n]; 
        
        i=0;
        j=100;
    }
 
    //Function to push an integer into the stack1.
    void push1(int x)
    {
        arr[i]=x;
        i++;
    }
    
    //Function to push an integer into the stack2.
    void push2(int x)
    {
       arr[j]=x;
       j++;
    }
    
    //Function to remove an element from top of the stack1.
    int pop1()
    {
        if(i==0)
        return -1;
        
        int temp=i-1;
        i--;
        return arr[temp];
        
    }
    
    //Function to remove an element from top of the stack2.
    int pop2()
    {
        //cout<<"j-> "<<j<<endl;
        if(j==100)
        return -1;
        
       int temp=j-1;
       j--;
       return arr[temp];
    }
};



//{ Driver Code Starts.

int main()
{

    int T;
    cin>>T;
    while(T--)
    {
        twoStacks *sq = new twoStacks();

        int Q;
        cin>>Q;
        while(Q--){
        int stack_no;
        cin>>stack_no;
        int QueryType=0;
        cin>>QueryType;
        
        if(QueryType==1)
        {
            int a;
            cin>>a;
            if(stack_no ==1)
            sq->push1(a);
            else if(stack_no==2)
            sq->push2(a);
        }else if(QueryType==2){
        	if(stack_no==1)
            cout<<sq->pop1()<<" ";
            else if(stack_no==2)
            cout<<sq->pop2()<<" ";

        }
        }
        cout<<endl;
    }
}

// } Driver Code Ends