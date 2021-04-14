// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function template in C++


class Solution
{
    public:
    //Function to check whether a set of numbers can be partitioned into 
    //two subsets such that the sum of elements in both subsets is same.
    
    bool subsetSum(int arr[],int s,int n){
        bool dp[n+1][s+1];
        for(int i=0;i<n+1;i++){
            for(int j=0;j<s+1;j++){
                if(i==0){
                    dp[i][j]=false;
                }
                if(j==0){
                    dp[i][j]=true;
                }
            }
        }
        for(int i=1;i<n+1;i++){
            for(int j=1;j<s+1;j++){
                if(arr[i-1]<=j){
                  dp[i][j]= dp[i-1][j-arr[i-1]] || dp[i-1][j];
                }
                else
                  dp[i][j]=dp[i-1][j];
            }
        }
        return dp[n][s];
    }
    bool findPartition(int a[], int n)
    {
        // code here
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=a[i];
        }
        if(sum%2==0){
            subsetSum(a,sum/2,n);
        }
        else
        return false;
    }
};

// { Driver Code Starts.
int main() {
    
    //taking total testcases
    int tc;
    cin >> tc;
    while (tc--) {
        
        //taking size of array
        int n, i;
        cin >> n;
        int a[n];
        
        //inserting elements in the array
        for (i = 0; i < n; i++) cin >> a[i];
        Solution ob;
        //calling findPartition() function and
        //printing "YES", if it returns true
        //else "NO"
        if (ob.findPartition(a, n))
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
  // } Driver Code Ends