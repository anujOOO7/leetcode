class Solution {
public:
    vector<vector<string>> res;
    bool isPalindrome(string &s,int i,int j){
        while(i<=j){
            if(s[i++]!=s[j--]) return false;
        }
        return true;
    }
    void f(string s,vector<string> &temp,int index){
        if(index==s.size()){
            res.push_back(temp);
            return ;
        }
        
        for(int i=index;i<s.size();i++){
            //if s.substr(index,i-index+1) is palindrome then move for next steps
            if(isPalindrome(s,index,i)){
                temp.push_back(s.substr(index,i-index+1));
                f(s,temp,i+1);
                temp.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<string> temp;
        f(s,temp,0);
        return res;
    }
};