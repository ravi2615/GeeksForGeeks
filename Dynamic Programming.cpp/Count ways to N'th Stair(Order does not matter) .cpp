// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends




class Solution
{
    public:
    //Function to count number of ways to reach the nth stair 
    //when order does not matter.
    long long countWays(int m)
    {
        // your code here
        long long dp[m+1];
        dp[0]=0;
        dp[1]=1;
        dp[2]=2;
        for(long long i=3;i<m+1;i++){
            dp[i]=(dp[i-2]+1);
        }
        
        // output
        // 0 1 2 3 4 5 6 7 8 9 10
        // 0 1 2 2 3 3 4 4 5 5 6
        return dp[m];
    }
};

// { Driver Code Starts.
int main()
{
    //taking count of testcases
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
}  // } Driver Code Ends