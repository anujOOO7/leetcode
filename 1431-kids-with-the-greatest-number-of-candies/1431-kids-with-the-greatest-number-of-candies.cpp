class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extra) {
    int max=*max_element(candies.begin(),candies.end());
    for(int &c:candies)
        c=c+extra>=max;
    return vector<bool>(candies.begin(),candies.end());
    }
};