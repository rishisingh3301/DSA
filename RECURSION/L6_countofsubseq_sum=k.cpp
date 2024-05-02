#include <bits/stdc++.h>
using namespace std;

int printsubsumk(int index, vector<int> &ds, int arr[], int length, int k, int sum)
{
    // printing of subsequence
    if (index == length)
    {
        if(sum==k){
        return 1;}
        return 0;
    }
    // take particular index
   
    sum+=arr[index];    
    int l=printsubsumk(index + 1, ds, arr, length, k, sum);

  
    sum-=arr[index];
    // not take particular index
    int r=printsubsumk(index + 1, ds, arr, length, k, sum);
    return l+r;
}

int main()
{

    int arr[] = {1,2,1,3,1,2};
    int length = 6;
    int k=4;
    vector<int> ds;
    cout<<printsubsumk(0, ds, arr, length,k,0);

    return 0;
}