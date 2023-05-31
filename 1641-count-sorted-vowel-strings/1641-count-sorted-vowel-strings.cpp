class Solution {
public:
    int f(int i, int n){
   		if(n==0) return 1;
   		if(i>=5) return 0;

   		return f(i,n-1)+f(i+1,n);
   }

   int countVowelStrings(int n) {
   	 return f(0,n);
   }
};