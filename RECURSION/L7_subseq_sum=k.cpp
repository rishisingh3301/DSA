#include <bits/stdc++.h>
using namespace std;

void printsubsumk(int index, vector<int> &ds, int arr[], int length, int k, int sum)
{
    // printing of subsequence
    if (index == length)
    {
        if(sum==k){
        for (auto it : ds)
        {
            cout << it << " ";
        }
        cout << endl;}
        return;
    }
    // take particular index
    ds.push_back(arr[index]);
    sum+=arr[index];    
    printsubsumk(index + 1, ds, arr, length, k, sum);

    ds.pop_back();
    sum-=arr[index];
    // not take particular index
    printsubsumk(index + 1, ds, arr, length, k, sum);
}

int main()
{

    int arr[] = {1,2,1,3,1,2};
    int length = 6;
    int k=4;
    vector<int> ds;
    printsubsumk(0, ds, arr, length,k,0);

    return 0;
}