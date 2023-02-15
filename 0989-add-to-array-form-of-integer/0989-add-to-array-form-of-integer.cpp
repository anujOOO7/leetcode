class Solution
{
public:
    vector<int> addToArrayForm(vector<int> &num, int k)
    {

        vector<int> v, ans;

        while (k)
        {
            v.emplace(v.begin(), k % 10);
            k /= 10;
        }

        if (num.size() > v.size())
        {
            int diff = num.size() - v.size();
            while (diff--)
            {
                v.emplace(v.begin(), 0);
            }
        }
        else
        {
            int diff = v.size() - num.size();
            while (diff--)
            {
                num.emplace(num.begin(), 0);
            }
        }

        int carry = 0;
        for (int i = v.size() - 1; i >= 0; i--)
        {
            int sum = num[i] + v[i] + carry;
            ans.emplace(ans.begin(), sum % 10);
            carry = sum / 10;
        }
        if (carry)
            ans.emplace(ans.begin(), carry);

        return ans;
    }
};