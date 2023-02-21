class Solution
{
public:
    int singleNonDuplicate(vector<int> &arr)
    {
        int left = 0, right = arr.size() - 1;
        while (left <= right)
        {
            int mid = (left + right) / 2;
            if ((mid == 0 || arr[mid] != arr[mid - 1]) && (mid == arr.size() - 1 || arr[mid] != arr[mid + 1]))
            {
                return arr[mid];
            }
            else if (arr[mid] == arr[mid - 1])
            {
                if (mid & 1)
                    left = mid+1;
                else
                    right = mid-2;
            }
            else if(arr[mid] == arr[mid + 1])
            {
                if (mid & 1)
                    right=mid-1;
                else
                    left=mid+2;
            }
        }
        return arr[left];
    }
};