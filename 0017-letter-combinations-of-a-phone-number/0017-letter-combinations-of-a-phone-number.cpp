class Solution {
public:
    void f(int i,string d,vector<string>& ans,string str)
    {
        if(i==d.size())
        {  if(str.size()>0)
            ans.push_back(str);
            return ;
        }
        if(d[i]=='2')
        {
            f(i+1,d,ans,str+'a');
            f(i+1,d,ans,str+'b');
            f(i+1,d,ans,str+'c');
        }
        else if(d[i]=='3')
        {
            f(i+1,d,ans,str+'d');
            f(i+1,d,ans,str+'e');
            f(i+1,d,ans,str+'f');
        }
        else if(d[i]=='4')
        {
           f(i+1,d,ans,str+'g');
            f(i+1,d,ans,str+'h');
            f(i+1,d,ans,str+'i');
        }
        else if(d[i]=='5')
        {
           f(i+1,d,ans,str+'j');
            f(i+1,d,ans,str+'k');
            f(i+1,d,ans,str+'l');
        }
        else if(d[i]=='6')
        {
            f(i+1,d,ans,str+'m');
            f(i+1,d,ans,str+'n');
            f(i+1,d,ans,str+'o');
        }
        else if(d[i]=='7')
        {
            f(i+1,d,ans,str+'p');
            f(i+1,d,ans,str+'q');
            f(i+1,d,ans,str+'r');
            f(i+1,d,ans,str+'s');
        }
        else if(d[i]=='8')
        {
          f(i+1,d,ans,str+'t');
            f(i+1,d,ans,str+'u');
            f(i+1,d,ans,str+'v');
        }
        else
        {
            f(i+1,d,ans,str+'w');
            f(i+1,d,ans,str+'x');
            f(i+1,d,ans,str+'y');
            f(i+1,d,ans,str+'z');
        }
    }
    vector<string> letterCombinations(string digits) 
    {
        vector<string> ans;
        string str="";
        f(0,digits,ans,str);
        return ans;
    }
};