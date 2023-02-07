class Solution {
public:
    bool detectCapitalUse(string word) {
        int c=word[0],d=word[1];
        
        //capital letters
        if(c>=65 && c<=90){
            if(d>=65 && d<=90){
                for(int i=2;i<word.length();i++){
                if(word[i]>90 || word[i]<65)
                    return false;
                }
            }
            else{
                for(int i=2;i<word.length();i++){
                if(word[i]>122 || word[i]<97)
                    return false;
                }
            }
        }
        
        //small letters
        else{
            for(auto ch:word){
                if(ch>122 || ch<97)
                    return false;
            }
        }
        return true;
    }
};