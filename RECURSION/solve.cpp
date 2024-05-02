#include <bits/stdc++.h>
using namespace std;
// void f(int ind,int arr[], int target,int len,vector<int> &ds){
  
//   if(ind==len){if(arr[ind]==target){
//     for(auto it:ds){cout<<it<<" ";}cout<<endl;return;
//   };}
//   int pick=0;
//   int notpick=0;
//   for(int i=0;i<len;i++){
    
//     if(arr[i]<=target){
//         ds.push_back(f(i+1,arr,target-arr[i],len,ds));}
 
//    f(i+1,arr,target,len,ds);
//   }
  
// }
class animal{
    public:
    void func(int a, float b){
        cout<<"roar";
    }
    int func(int a,float c,float d){
        cout<<a+d+c;
    }
  
};

// To execute C++, please define "int main()"
int main() {
  // auto words = { "Hello, ", "World!", "\n" };
  // for (const char* const& word : words) {
  //   cout << word;
  // }
  animal lion;
  lion.func(1,1.0);
  
  // int n=24;
  // vector<int> ans;
  // if(n==1)ans.push_back(1);
  // for(int i=2;i<=n;i++){
  //   while(n%i==0){
  //     n=n/i;
  //     ans.push_back(i);
  //   }
  // }
  // for(int i=0;i<ans.size();i++){
  //   cout<<ans[i]<<" ";
  // }
//   int arr[]={12, 10, 2, 2,4,6,8,10,12,12,14};
//   int target=16;
//   vector<int> ds;
//   f(10,arr,target,11,ds);



  return 0;
}

// primeFactorization( 6 ) == [2,3]
// primeFactorization( 5 ) == [5]
// primeFactorization( 12 ) == [2,2,3]

// Given an array of unsorted numbers [12, 10, 2, 2,4,6,8,10,12,12,14] and a number n = 16, find all combinations of numbers from array which sum upto n. 
// Expected output: [12, 2, 2], [12, 4], [2, 8, 6]

// Your previous Plain Text content is preserved below:

// This is just a simple shared plaintext pad, with no execution capabilities.

// When you know what language you'd like to use for your interview,
// simply choose it from the dots menu on the tab, or add a new language
// tab using the Languages button on the left.

// You can also change the default language your pads are created with
// in your account settings: https://app.coderpad.io/settings

// Enjoy your interview!