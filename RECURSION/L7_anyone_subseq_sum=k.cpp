#include <bits/stdc++.h>
using namespace std;

bool printsubsumk(int index, vector<int> &ds, int arr[], int length, int k, int sum)
{
    // printing of subsequence
    if (index == length)
    {
        if(sum==k){
        for (auto it : ds)
        {
            cout << it << " ";
        }
        cout << endl;
        return true;}
        return false;
    }
    // take particular index
    ds.push_back(arr[index]);
    sum+=arr[index];    
    if(printsubsumk(index + 1, ds, arr, length, k, sum)==true){return true;}

    ds.pop_back();
    sum-=arr[index];
    // not take particular index
    if(printsubsumk(index + 1, ds, arr, length, k, sum)==true){return true;}
    return false;
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