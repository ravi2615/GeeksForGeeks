// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution
{
    public:
    //Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        //Your code here
        int a[3]={x,y,z};
        sort(a,a+3);
        int dp[4][n+1];
        for(int i=0;i<=3;i++)
        {
                for(int j=0;j<=n;j++)
                {
                    if(i==0)
                    dp[i][j]=INT_MIN;
                    else if(j==0)
                    dp[i][j]=0;
                    else if(a[i-1]<=j)
                    dp[i][j]=max(dp[i-1][j],1+dp[i][j-a[i-1]]);
                    else
                    dp[i][j]=dp[i-1][j];
                }
        }
        return dp[3][n]<0?0:dp[3][n];
    }
};

// { Driver Code Starts.
int main() {
    
    //taking testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking length of line segment
        int n;
        cin >> n;
        
        //taking types of segments
        int x,y,z;
        cin>>x>>y>>z;
        Solution obj;
        //calling function maximizeTheCuts()
        cout<<obj.maximizeTheCuts(n,x,y,z)<<endl;

    }

	return 0;
}  // } Driver Code Ends