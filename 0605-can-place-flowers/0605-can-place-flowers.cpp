class Solution {
public:
    bool canPlaceFlowers(vector<int>& f, int n) {
        int count=0;
        int k=f.size();
        f.emplace(f.begin(),0);
        f.push_back(0);
        for(int i=1;i<f.size()-1;i++)
        {
            if(f[i-1]+f[i]+f[i+1]==0)
            {
                count++;
                i++;
            }
        }
        return count>=n;
    }
};