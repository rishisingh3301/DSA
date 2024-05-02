#include <bits/stdc++.h>
using namespace std;

void printsub(int index, vector<int> &ds, int arr[], int length)
{
    // printing of subsequence
    if (index == length)
    {
        for (auto it : ds)
        {
            cout << it << " ";
        }
        cout << endl;
        return;
    }
    // take particular index
    ds.push_back(arr[index]);
    printsub(index + 1, ds, arr, length);

    ds.pop_back();
    // not take particular index
    printsub(index + 1, ds, arr, length);
}

int main()
{

    int arr[] = {3, 1, 2, 7, 4};
    int length = 5;
    vector<int> ds;
    printsub(0, ds, arr, length);

    return 0;
}