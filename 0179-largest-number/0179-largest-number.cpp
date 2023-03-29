bool cmp(string a,string b){
        return a+b>b+a;

}
class Solution {
public:
    string largestNumber(vector<int>& nums)
    {
        string s;
        vector<string> ans;

        for(int it: nums)
            ans.push_back(to_string(it));

        sort(ans.begin(),ans.end(),cmp);
        if(ans[0]=="0") return "0";
        
        for(string a:ans) s+=a;
        return s;
    }
};