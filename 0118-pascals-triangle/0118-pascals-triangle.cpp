class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> ans;
        for(int i=0;i<n;i++)
        {
            vector<int> v;
            if(i==0)
                v.push_back(1);
            else
            {
                v.push_back(1);
                for(int j=0;j<=i-2;j++)
                {
                    v.push_back(ans[i-1][j]+ans[i-1][j+1]);
                }
                v.push_back(1);
            }
            ans.push_back(v);
        }
        return ans;
    }
};