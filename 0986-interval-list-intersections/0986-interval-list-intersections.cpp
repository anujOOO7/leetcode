class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& f, vector<vector<int>>& s) {
        vector<vector<int>> res;
        for(int i=0;i<f.size();i++){
            for(int j=0;j<s.size();j++){
                if(f[i][1]>=s[j][0])
                    if(max(f[i][0],s[j][0])<=min(f[i][1],s[j][1]))
                    res.push_back({max(f[i][0],s[j][0]),min(f[i][1],s[j][1])});
            }
        }
        return res;
    }
};