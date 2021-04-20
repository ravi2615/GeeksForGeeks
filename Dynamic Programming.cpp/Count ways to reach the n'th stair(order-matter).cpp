// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution
{
    public:
    //Function to count number of ways to reach the nth stair.
    int countWays(int n)
    {
        // your code here
        long long dp[n+1];
        dp[0]=0;
        dp[1]=1;
        dp[2]=2;
        for(long long i=3;i<n+1;i++){
            dp[i]=(dp[i-1]+dp[i-2])%1000000007;
        }
        // output
        // 0 1 2 3 4 5  6  7  8  9 10
        // 0 1 2 3 5 8 13 21 34 55 89
        return dp[n];
    }
};



// { Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking stair count
        int m;
        cin>>m;
        Solution ob;
        cout<<ob.countWays(m)<<endl; // Print the output from our pre computed array
    }
    return 0;
}
  // } Driver Code Ends