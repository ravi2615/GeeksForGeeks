// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution{
  public:
/*You are required to complete this method*/
    int wildCard(string pattern,string str)
    {
        int n=str.size();
        int m=pattern.size();
        bool dp[n+1][m+1];
        
        memset(dp,0,sizeof(dp));
      dp[0][0]=true;
      for(int i=1;i<m+1;i++)
      if(pattern[i-1]=='*')
      dp[0][i]=dp[0][i-1];
      for(int i=1;i<n+1;i++){
          for(int j=1;j<m+1;j++){
          if(str[i-1]==pattern[j-1]||pattern[j-1]=='?'){
              dp[i][j]=dp[i-1][j-1];
          }
          else if(pattern[j-1]=='*')
          dp[i][j]=dp[i][j-1]||dp[i-1][j];
          }
        
      }
      
      return dp[n][m];
    }
};

// { Driver Code Starts.
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
           string pat,text;
           cin>>pat;
cin.ignore(numeric_limits<streamsize>::max(),'\n');
           cin>>text;
           Solution obj;
           cout<<obj.wildCard(pat,text)<<endl;
   }
}
  // } Driver Code Ends