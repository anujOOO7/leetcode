class Solution {
public:
    int minFlips(int a, int b, int c) {
        int x,y,z,cnt=0;
        while(a||b||c){
            x=a&1; y=b&1; z=c&1;
            if(z && !(x|y)) cnt++;
            if(!z){
                cnt+=(x==1)+(y==1);
            }
            a/=2; b/=2; c/=2;
        }
        return cnt;
    }
};