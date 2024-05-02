class Solution {
public:
    vector<vector<string>> findLadders(string start, string finish,
                                       vector<string>& wordPool) {
        // initialization

        set<string> st(wordPool.begin(), wordPool.end());
        queue<vector<string>> q;
        vector<string> usedonlevel;
        vector<vector<string>> ans;

        // inserting values
        int level = 0;
        q.push({start});
        usedonlevel.push_back(start);

        // bfs
        while (!q.empty()) {
            vector<string> vec = q.front();
            q.pop();
            string word = vec.back();
            // deleting from set if new level is found
            if (vec.size() > level) {
                level++;
                for (auto it : usedonlevel) {
                    st.erase(it);
                }
                usedonlevel.clear();
            }
            // storing into answer
            if (word == finish) {
                // if(ans.size()==0){
                ans.push_back(vec);
                // }
                // else{
                //     if(vec.size()==ans[0].size()){
                //         ans.push_back(vec);
                //     }
                // }
            }
            // iterating and finding new words
            for (int i = 0; i < word.size(); i++) {
                char original = word[i];
                for (char c = 'a'; c <= 'z'; c++) {
                    word[i] = c;
                    if (st.find(word) != st.end()) {
                        vec.push_back(word);
                        q.push(vec);
                        usedonlevel.push_back(word);
                        vec.pop_back();
                    }
                }
                word[i] = original;
            }
        }
        return ans;
    }
};