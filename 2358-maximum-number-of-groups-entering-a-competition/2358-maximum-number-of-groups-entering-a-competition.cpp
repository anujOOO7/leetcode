class Solution
{
public:
    int maximumGroups(vector<int> &grades)
    {
        sort(grades.begin(), grades.end());

        int pSum = 0, cSum = 0;
        int pCnt = 0, cCnt = 0, res = 0;

        for (int grade : grades)
        {
            cSum += grade;
            cCnt++;
            if (cCnt > pCnt && cSum > pSum)
            {
                res++;
                pSum = cSum;
                pCnt = cCnt;
                cSum = cCnt = 0;
            }
        }
        return res;
    }
};