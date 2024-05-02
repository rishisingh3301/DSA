#include <bits/stdc++.h>
using namespace std;
#define int long long int


signed main()
{
    int t=1;
    while(t--)
    {
   
        int n;cin>>n;
        vector<int>v(n+1),hash(n+1),ans(n+1);
        for(int i=1;i<=n;i++)
        {
            cin>>v[i];
            hash[v[i]]=i;
        }
        bool flag=false;
        for(int i=1;i<=n;i++)
        {
            if(hash[i]!=i)
            {
                flag=true;
            }
        }
        if(flag){
            for(int i=1;i<=n;i++)cout<<hash[v[i]]<<" ";
            cout<<endl;
        }
        else{
            cout<<2<<" "<<1<<" ";
            for(int i=3;i<=n;i++)cout<<hash[i]<<" ";
            cout<<endl;
        }
    }
    return 0;
}