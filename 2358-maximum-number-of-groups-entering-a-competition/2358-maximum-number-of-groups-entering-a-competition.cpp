class Solution
{
public:
    int maximumGroups(vector<int> &grades)
    {
        sort(grades.begin(), grades.end());
        int n = grades.size();
        int count = 0;
        if (n == 2)
            return 1;
        int i = 0;
        while (i < n)
        {
            count += 1;
            i += count + 1;
        }
        return count;
    }
};