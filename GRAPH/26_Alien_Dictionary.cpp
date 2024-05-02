#include<bits/stdc++.h>
vector<int> toposort(vector<int> adj[],int n){
    int indegree[n]={0};
    for(int i=0;i<n;i++){
        for(auto it : adj[i]){
            indegree[it]++;
        }
    }
    queue<int> q;
    vector<int> ans;
    for(int i=0;i<n;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int node=q.front();
        q.pop();
        ans.push_back(node);
        for(auto it : adj[node]){
            indegree[it]--;
            if(indegree[it]==0){
                q.push(it);
            }
        }
    }
    return ans;
}

string getAlienLanguage(vector<string> &dictionary, int k)
{
    //make adj list of numbers using string comparison upto minimum length
    //do topo sort you'll get vector of int, return a string of characters of those vectors
    int n=dictionary.size();
    vector<int> adj[k];
    for(int i=0;i<n-1;i++){
        string s1=dictionary[i];
        string s2=dictionary[i+1];
        int minsize=min(s1.size(),s2.size());
        for(int j=0;j<minsize;j++){
            if(s1[j]!=s2[j]){
                adj[s1[j]-'a'].push_back(s2[j]-'a');
                break;
            }
        }
    }
    vector<int> topo=toposort(adj, k);
    string s="";
    for(int i=0;i<topo.size();i++){
        s=s+(char(topo[i]+'a'));
    }
    return s;
}