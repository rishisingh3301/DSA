class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        //make a set to store words so that it will take less time to search
        //make queue and push starting word and in loop search by changing each 
        //character
        queue<pair<string,int>>q;
        q.push({beginWord,1});
        set<string> st(wordList.begin(),wordList.end());
        st.erase(beginWord);//don't forget to erase       
        while(!q.empty()){
            string word=q.front().first;
            int step=q.front().second;
            q.pop();
            if(word==endWord){return step;}
            for(int i=0;i<word.size();i++){
                char letter=word[i];//we stored this to get our original word back
                for(char newchar='a';newchar<='z';newchar++){
                    word[i]=newchar;
                    if(st.find(word)!=st.end()){
                        q.push({word,step+1});
                        st.erase(word);
                    }
                }
                word[i]=letter;
            }
        }
        return 0;
    }
};