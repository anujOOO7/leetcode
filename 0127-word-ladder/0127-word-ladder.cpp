class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string,int>> q;
        q.push({beginWord,1});
        
        unordered_set<string> st(wordList.begin(),wordList.end());
        st.erase(beginWord);
        
        while(!q.empty()){
            string word=q.front().first;
            int steps=q.front().second;
            q.pop();
            if(word==endWord) return steps;
            
            for(int i=0;i<word.size();i++){
                string s=word;
                for(char j='a';j<='z';j++){
                    s[i]=j;
                    if(st.count(s)){
                        q.push({s,steps+1});
                        st.erase(s);
                    }
                }
            }
        }
        return 0;
    }
};