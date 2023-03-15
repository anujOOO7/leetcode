class Solution {
public:
    string getPermutation(int n, int k) {
        string s,ans;
        for(int i=1;i<=n;i++){
            s+=to_string(i);
        }
        while(--k){
            next_permutation(s.begin(),s.end());
        }
        ans+=s;
        return ans;
    }
};