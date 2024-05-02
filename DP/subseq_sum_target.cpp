
#include <bits/stdc++.h>
using namespace std;

// Function to check if there is a subset of 'arr' with a sum equal to 'k'
bool subsetSumToK(int n, int k, vector<int> &arr) {

    vector<bool> prev(5,false);
    vector<bool> curr(5,false);

        prev[0] = true;
   
    if (arr[0] <= k) {
        prev[arr[0]] = true;
    }
    // Fill the DP array iteratively
    for (int ind = 1; ind < n; ind++) {
        for (int target = 1; target <= k; target++) {

            bool notTaken = prev[target];

            // If we take the current element, subtract its value from the target and check the previous row
            bool taken = false;
            if (arr[ind] <= target) {
                taken = prev[target - arr[ind]];
            }

            curr[target] = notTaken || taken;
        }
        prev=curr;
    }

    return prev[k];
}

int main() {
    vector<int> arr = {2,5,1,6};
    int k = 4;
    int n = arr.size();

    // Call the subsetSumToK function and print the result
    if (subsetSumToK(n, k, arr))
        cout << "Subset with the given target found";
    else
        cout << "Subset with the given target not found";


    /*
         0 1 2 3 4

    2    1 0 1 0 0 
    5    1 0 1 0 0 
    1    1 1 1 1 0 
    6    1 1 1 1 0 
    7    1 1 1 1 0 
    
    not taken 0 or taken 1
    dp[1][2]=1
    
    
    */
    // subsetSumToK(n, k, arr);

    return 0;
}
