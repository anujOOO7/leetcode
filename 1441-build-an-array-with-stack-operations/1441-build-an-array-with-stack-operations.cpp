class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        int k=0;
        vector<string> ans;
        for(int i=0;i<target.size();i++)
        {
            ans.push_back("Push");
            if(target[i]==k+1)
            { 
                k++;
                continue;
            }
            else
            {
                k++;
                while(target[i]!=k){
                    ans.push_back("Pop");
                    ans.push_back("Push");
                    k++;
                }
            }
        }
        return ans;
    }
};