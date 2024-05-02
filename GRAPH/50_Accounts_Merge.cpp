class DisjointSet {
public:
    vector<int> parent, rank, size;
    DisjointSet(int n) {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        size.resize(n + 1, 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int findpar(int node) {
        if (parent[node] == node) {
            return node;
        }
        return parent[node] = findpar(parent[node]);
    }

    void unionbyrank(int u, int v) {
        int pu = findpar(u);
        int pv = findpar(v);
        if (pu == pv) {
            return;
        }
        if (rank[pu] < rank[pv]) {
            parent[pu] = pv;
        } else if (rank[pv] < rank[pu]) {
            parent[pv] = pu;
        } else {
            parent[pv] = pu;
            rank[pu]++;
        }
    }
    void unionbysize(int u, int v) {
        int pu = findpar(u);
        int pv = findpar(v);
        if (pu == pv) {
            return;
        }
        if (size[pu] < size[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
        } else if (rank[pv] < rank[pu]) {
            parent[pv] = pu;
            size[pu] += size[pv];
        } else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        // first create a map where string and id are mapped
        // strings which are already mapped, make union of that index and the
        // one to which it's already mapped
        int n = accounts.size();
        DisjointSet ds(n);
        unordered_map<string, int> um;
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                string mail = accounts[i][j];
                if (um.find(mail) == um.end()) { // email not registered before
                    um[mail] = i;
                } else { // this mail is registered before
                    // make union of this mail index with earlier to which it
                    // was registered
                    ds.unionbyrank(i, um[mail]);
                }
            }
        }

        // store all same mails in a vector
        vector<string> allmail[n];
        for (auto it : um) {
            string mail = it.first;
            int node = ds.findpar(it.second);
            allmail[node].push_back(mail);
        }
        // add name in vector and sort the vector
        vector<vector<string>> ans;
        for (int i = 0; i < n; i++) {
            if (allmail[i].size() != 0) {
                vector<string> temp;
                string name = accounts[i][0];
                temp.push_back(name);
                sort(allmail[i].begin(), allmail[i].end());
                for (auto it : allmail[i]) {
                    temp.push_back(it);
                }
                ans.push_back(temp);
            }
        }
        return ans;
    }
};