class Solution {
public:
    using ll=long long;
    long long totalCost(vector<int>& costs, int k, int c) {
        int n=costs.size();
        priority_queue<int,vector<int>,greater<int>> l,r;
        ll sum=0;
        int i=0,j=n-1;
        while(i<c){
            l.push(costs[i]);
            i++;
        }
        while(j>=i && j>n-c-1){
            r.push(costs[j]);
            j--;
        }
        
        while(k--){
            if(l.empty()){
                sum+=r.top();
                r.pop();
                if(i<=j){
                    r.push(costs[j]);
                    j--;
                }
            }
            else if(r.empty()){
                sum+=l.top();
                l.pop();
                if(i<=j){
                    l.push(costs[j]);
                    j++;
                }
            }
            else if(l.top()<=r.top()){
                sum+=l.top();
                l.pop();
                if(i<=j){
                    l.push(costs[i]);
                    i++;
                }
            }
            else{
                sum+=r.top();
                r.pop();
                if(i<=j){
                    r.push(costs[j]);
                    j--;
                }
            }
        }
        return sum;
    }
};