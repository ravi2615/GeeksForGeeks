// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++


class Solution
{
    public:
    //Function to find length of shortest common supersequence of two strings.
    int shortestCommonSupersequence(char* X, char* Y, int m, int n)
    {
        //code here
         int dp[m+1][n+1];
        for(int i=0;i<m+1;i++){
            for(int j=0;j<n+1;j++)
            if(i==0||j==0)
            dp[i][j]=0;
            else{
                if(X[i-1]==Y[j-1])
                dp[i][j]= 1+ dp[i-1][j-1];
                else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return n+m-dp[m][n];
    }
};

// { Driver Code Starts.

int main()
{   
    
    int t;
    char X[10001], Y[10001];
    
    //taking total testcases
    cin >> t;
    while(t--){
    
    //taking String X and Y
	cin >> X >> Y;
	
	//calling function shortestCommonSupersequence()
	Solution obj;
	cout << obj.shortestCommonSupersequence(X, Y, strlen(X), strlen(Y))<< endl;
    }
	return 0;
}

  // } Driver Code Ends