class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(begin(people),end(people));
        int n=people.size()-1;
        int i=0,j=n,count=0;
        while(i<=j)
        {
            // cout<<count<<endl;
            if(people[i]+people[j]<=limit)
            {
                i++;
                j--;
            }
            else
            {
                j--;
            }
            ++count;
        }
        return count;
    }
};