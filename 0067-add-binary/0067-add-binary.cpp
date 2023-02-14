class Solution {
public:
    string addBinary(string a, string b) {
        if(b.size() > a.size()) 
            swap(a,b);
        while(b.size() < a.size()) 
            b = "0" + b;
        
        int carry=0;
        string ans;
        int i=a.size();
        
        while(i--){
            int sum=a[i]-'0'+b[i]-'0'+carry;
            if(sum==3){
                ans="1"+ans;
                carry=1;
            }
            else if(sum==2){
                ans="0"+ans;
                carry=1;
            }
            else if(sum==1){
                ans="1"+ans;
                carry=0;
            }
            else{
                ans="0"+ans;
            }
        }
        if(carry)
            ans="1"+ans;
        return ans;
    }
};