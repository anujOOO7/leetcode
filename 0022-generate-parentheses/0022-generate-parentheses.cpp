class Solution {
public:
    vector<string> v;
    void gen(int op,int cl,int n,string &s){
        if(op+cl==2*n)
        {
            v.push_back(s);
            return;
        }
        // try for open
        if(op+1<=n)
        {
            s.push_back('(');
            gen(op+1,cl,n,s);
            s.pop_back();
        }
        //try for close
        if(cl+1<=n&&op>=cl+1)
        {
            s.push_back(')');
            gen(op,cl+1,n,s);
            s.pop_back();
        }
    }
    
    vector<string> generateParenthesis(int n) {
        string ans="";
        gen(0,0,n,ans);
        return v;
    }
};