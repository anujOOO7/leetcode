class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> ans;
        map<char,int> m;
        int n=s.length();
        for(int i=0;i<n;i++){
            m[s[i]]=i;
        }
        
        int prev=-1;
        for(int i=0;i<n;i++){
            int lastOcc=m[s[i]];
            int j=i;
            while(j<lastOcc){
                if(lastOcc<m[s[j]]){
                    lastOcc=m[s[j]];
                }
                j++;
            }
            
            if(j==lastOcc){
                ans.push_back(lastOcc-prev);
                prev=lastOcc;
            }
            if(lastOcc==n-1)
                break;
            i=j;
        }
        return ans;
    }
};