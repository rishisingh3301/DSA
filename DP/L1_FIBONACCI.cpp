#include <bits/stdc++.h>
using namespace std;

//MOST SPACE AND TIME OPTIMIZED METHOD
int main()
{
    int n=10;
    //step 1 initialize dp
    vector <int>dp(n+1,-1);
    dp[0]=0;dp[1]=1;
    cout<<0<<" "<<1<<" ";
    int prev=1,prev2=0;
    //you are not storing or maintaing a dataset, you only using variables
    for (int i = 2; i < n; i++)
    {
        int curr=prev+prev2;
        prev2=prev;
        prev=curr;
        cout<<prev<<" ";
    }
    
    
    cout<<endl;
    return 0;
}




// //TABULATION METHOD -> BOTTOM UP APPROACH
// int main()
// {
//     int n=10;
//     //step 1 initialize dp
//     vector <int>dp(n+1,-1);
//     dp[0]=0;dp[1]=1;
//     cout<<0<<" "<<1<<" ";

//     //whatever implementation you have for recursion convert it to dp variable and put in for loop
//     for (int i = 2; i < n; i++)
//     {
//         dp[i]=dp[i-1]+dp[i-2];
//         cout<<dp[i]<<" ";
//     }
    
    
//     cout<<endl;
//     return 0;
// }




// //DP METHOD
// int fib(int n, vector<int> &dp)
// {
//     if(n<=1){return n;}

//     //step 2 checking if that value already in dp or not
//     if(dp[n]!=-1){return dp[n];}

//     //step 3 updating dp value storing the already computed answer of subproblem
//     return dp[n]=fib(n-1,dp)+fib(n-2,dp);
// }

// int main()
// {
//     int n=10;
//     //step 1 initialize dp
//     vector <int>dp(n+1,-1);
//     for (int i = 0; i < n; i++)
//     {
//         cout<<fib(i,dp)<<" ";
//     }
//     cout<<endl;
//     return 0;
// }



//RECURSION METHOD
// int fib(int n)
// {
//     if(n<=1){return n;}

//     return fib(n-1)+fib(n-2);
// }

// int main()
// {
//     int n=10;
//     for (int i = 0; i < n; i++)
//     {
//         cout<<fib(i)<<" ";
//     }
//     cout<<endl;
//     return 0;
// }