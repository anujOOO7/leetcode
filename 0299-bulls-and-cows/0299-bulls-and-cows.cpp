class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<char,int>m;
        unordered_map<char,int>n;
        string str;
        int c = 0;
        for(int i=0;i<secret.size();i++){
            if(secret[i]==guess[i]){
                c++;
            }
        }
        str += to_string(c);
        str += 'A';
        for(auto i:secret){
            m[i]++;
        }
        for(auto i:guess){
            n[i]++;
        }
        int cnt = 0;
        for(auto i:m){
            for(auto j:n){
                if(i.first==j.first){
                    cnt += min(i.second,j.second);
                }
            }
        }
        cnt = cnt - c;
        cout << cnt;
        str += to_string(cnt);
        str += 'B';
        return str;
    }
};