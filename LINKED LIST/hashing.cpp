#include<bits/stdc++.h>
using namespace std;

int main()
{
    int arr[]={1,5,4,2,1,5,6,3,7};
    int n;cin>>n;
    //preparing hash table
    int hash[10]={0};
    for (int i = 0; i < 9; i++)
    {
        hash[arr[i]]+=1;
    }
    
    while(n--){
        int num;cin>>num;
        //fetching
        cout<<"count of "<<num<<" is "<<hash[num]<<endl;
    }
    return 0;
}