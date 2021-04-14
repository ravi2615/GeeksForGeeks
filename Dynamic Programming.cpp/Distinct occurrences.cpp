// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
 

 // } Driver Code Ends
/*You are required to complete this method*/

class Solution
{
    public:
 long long int subsequenceCount(string S, string T)
    {
      //Your code here
      long long int sSize=S.size(),tSize=T.size();
      if(tSize>sSize)
      return 0;
      
      long long int dp[tSize+1][sSize+1];
      
   
          for(long long int i=1;i<tSize+1;i++)
              dp[i][0] = 0;
          
            for(long long int j=0;j<sSize+1;j++)
              dp[0][j] = 1;
          
      for(long long int i=1;i<tSize+1;i++){
          for(long long int j=1;j<sSize+1;j++){
          if(T[i-1]==S[j-1]){
              dp[i][j]=dp[i][j-1]+dp[i-1][j-1]%1000000007;
          }
          else
          dp[i][j]=dp[i][j-1];
          }
        //   cout<<dp[i][j]<<" ";}cout<<endl;
      }
      
      return dp[tSize][sSize]%1000000007;
    }
};
 

