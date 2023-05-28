class Solution {
public:
    vector<string> ans;
    vector<string> f(int i,string &digits,string s){
        if(i==digits.length()){
            if(s.size()>0) ans.push_back(s);
            return ans;
        }
        
        if(digits[i]=='2'){
            f(i+1,digits,s+'a');
            f(i+1,digits,s+'b');
            f(i+1,digits,s+'c');
        }
        if(digits[i]=='3'){
            f(i+1,digits,s+'d');
            f(i+1,digits,s+'e');
            f(i+1,digits,s+'f');
        }
        if(digits[i]=='4'){
            f(i+1,digits,s+'g');
            f(i+1,digits,s+'h');
            f(i+1,digits,s+'i');
        }
        if(digits[i]=='5'){
            f(i+1,digits,s+'j');
            f(i+1,digits,s+'k');
            f(i+1,digits,s+'l');
        }
        if(digits[i]=='6'){
            f(i+1,digits,s+'m');
            f(i+1,digits,s+'n');
            f(i+1,digits,s+'o');
        }
        if(digits[i]=='7'){
            f(i+1,digits,s+'p');
            f(i+1,digits,s+'q');
            f(i+1,digits,s+'r');
            f(i+1,digits,s+'s');
        }
        if(digits[i]=='8'){
            f(i+1,digits,s+'t');
            f(i+1,digits,s+'u');
            f(i+1,digits,s+'v');
        }
        if(digits[i]=='9'){
            f(i+1,digits,s+'w');
            f(i+1,digits,s+'x');
            f(i+1,digits,s+'y');
            f(i+1,digits,s+'z');
        }
        return ans;
    }
    vector<string> letterCombinations(string digits) {
        return f(0,digits,"");
    }
};