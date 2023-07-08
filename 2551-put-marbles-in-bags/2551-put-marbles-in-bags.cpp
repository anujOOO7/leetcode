class Solution {
public:
    using ll=long long;
    long long putMarbles(vector<int>& weights, int k) {
        priority_queue<ll> maxHeap;
        priority_queue<ll,vector<ll>,greater<ll>> minHeap;
        ll mx=0,mn=0;
        for(int i=1;i<weights.size();i++){
            maxHeap.push(weights[i]+weights[i-1]);
            minHeap.push(weights[i]+weights[i-1]);
        }
        while(k>1){
            mx+=maxHeap.top(); 
            mn+=minHeap.top();
            maxHeap.pop();
            minHeap.pop();
            k--;
        }
        return mx-mn;
    }
};