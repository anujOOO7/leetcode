class Solution {
public:
    int partitionString(string s) {
        map<char,int> m;
        int i=0,count=1;
        while(i<s.length()){
            m[s[i]]++;
            if(m[s[i]]==2){
                count++;
                m.clear();
                m[s[i]]++;
            }
            i++;
        }
        return count;
    }
};