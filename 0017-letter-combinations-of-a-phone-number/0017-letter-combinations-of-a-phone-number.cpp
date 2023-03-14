class Solution {
public:
    vector<string> ans;
    void f(int i,string d,string str)
    {
        if(i==d.size())
        {  
            if(str.size()>0)
                ans.push_back(str);
            return ;
        }
        if(d[i]=='2')
        {
            f(i+1,d,str+'a');
            f(i+1,d,str+'b');
            f(i+1,d,str+'c');
        }
        else if(d[i]=='3')
        {
            f(i+1,d,str+'d');
            f(i+1,d,str+'e');
            f(i+1,d,str+'f');
        }
        else if(d[i]=='4')
        {
            f(i+1,d,str+'g');
            f(i+1,d,str+'h');
            f(i+1,d,str+'i');
        }
        else if(d[i]=='5')
        {
            f(i+1,d,str+'j');
            f(i+1,d,str+'k');
            f(i+1,d,str+'l');
        }
        else if(d[i]=='6')
        {
            f(i+1,d,str+'m');
            f(i+1,d,str+'n');
            f(i+1,d,str+'o');
        }
        else if(d[i]=='7')
        {
            f(i+1,d,str+'p');
            f(i+1,d,str+'q');
            f(i+1,d,str+'r');
            f(i+1,d,str+'s');
        }
        else if(d[i]=='8')
        {
            f(i+1,d,str+'t');
            f(i+1,d,str+'u');
            f(i+1,d,str+'v');
        }
        else
        {
            f(i+1,d,str+'w');
            f(i+1,d,str+'x');
            f(i+1,d,str+'y');
            f(i+1,d,str+'z');
        }
    }
    vector<string> letterCombinations(string digits) 
    {
        string str;
        f(0,digits,str);
        return ans;
    }
};