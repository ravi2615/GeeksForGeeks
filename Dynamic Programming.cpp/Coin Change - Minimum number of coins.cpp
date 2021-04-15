// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//Complete this function

class Solution
{
    public:
    //Function to find the minimum number of coins to make the change 
    //for value using the coins of given denominations.
    long long minimumNumberOfCoins(int coins[],int numberOfCoins,int value)
    {
        // your code here
        int dp[numberOfCoins+1][value+1];
        for(int i=0;i<=value;i++)
        {
           dp[0][i]=INT_MAX-1;
        }
        for(int i=0;i<=numberOfCoins;i++)
        {
           dp[i][0]=0;
        }
        for(int i=0;i<=numberOfCoins;i++)
        for(int j=1;j<=value;j++)
        {
           if(j%coins[0]==0)
           dp[i][j]=j/coins[0];
           else
           dp[i][j]=INT_MAX-1;
        }
        for(int i=1;i<=numberOfCoins;i++)
        {
                for(int j=1;j<=value;j++)
                {
                    if(coins[i-1]<=j)
                    dp[i][j]=min(dp[i][j-coins[i-1]]+1,dp[i-1][j]);
                    else
                    dp[i][j]=dp[i-1][j];
                }
        }
        if(dp[numberOfCoins][value] == INT_MAX-1 || dp[numberOfCoins][value] == 0)
            return -1;
            else
            return dp[numberOfCoins][value];
    }
};

// { Driver Code Starts.



int main() {
	
	//taking total count of testcases
	int testcases;
	cin>>testcases;
	while(testcases--)
	{
	    //taking value
	    int value;
	    cin>>value;
	    
	    //taking number of coins
	    int numberOfCoins;
	    cin>>numberOfCoins;
	    int coins[numberOfCoins];
	    
	    //taking value of each coin
	    for(int i=0;i<numberOfCoins;i++)
	    cin>>coins[i];
	    Solution obj;
	    //calling function minimumNumberOfCoins()
	    int answer=obj.minimumNumberOfCoins(coins,numberOfCoins,value);
	    
	    //printing "Not Possible" if answer is -1
	    //else printing answer
	    if(answer==-1)
	    cout<<"Not Possible"<<endl;
	    else
	    cout<<answer<<endl;
	    
	}
	return 0;
}  // } Driver Code Ends