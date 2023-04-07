class Solution {
public:
    int maximumScore(int a, int b, int c) {
        priority_queue<int> pq;
        int count=0;
        pq.push(a);
        pq.push(b);
        pq.push(c);
        while(pq.size()>=2){
            int x=pq.top(); pq.pop();
            int y=pq.top(); pq.pop();
            count++; --x; --y;
            if(x) pq.push(x);
            if(y) pq.push(y);
        }
        return count;
    }
};