class Solution {
public:
    int n,m;
    vector<int> ans;
    void f(int i,vector<int>& temp,vector<bool>& extra,vector<int>& arr){
        if(i==(1<<n)-1){
            if(!ans.size() || temp.size()<ans.size()) ans=temp;
            return;
        }
        if(!ans.empty() && temp.size()>=ans.size()) return;
        
        int cnt=0;
        while(((i>>cnt)&1)) cnt++;
        
        for(int j=0;j<m;j++){
            if(extra[j]) continue;
            if(((arr[j]>>cnt)&1)){
                temp.push_back(j);
                f(i|arr[j],temp,extra,arr);
                temp.pop_back();
            }
        }
    }
    
    vector<int> smallestSufficientTeam(vector<string>& req, vector<vector<string>>& people) {
        n=req.size(),m=people.size();
        unordered_map<string,int> mp;
        for(int i=0;i<n;i++) mp[req[i]]=i;
        
        vector<int> arr(m,0);
        for(int i=0;i<m;i++){
            int mask=0;
            for(string& skill:people[i]) {
                mask|=1<<mp[skill];
            }
            arr[i]=mask;
        }
        
        vector<bool> extra(m,false);
        for(int i=0;i<m;i++){
            for(int j=i+1;j<m;j++){
                int val=arr[i]|arr[j];
                if(val==arr[i]) extra[j]=true;
                else if(val==arr[j]) extra[i]=true;
            }
        }
        vector<int> temp;
        f(0,temp,extra,arr);
        return ans;
    }
};