//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    // //Function to return the total number of possible unique BST. 
    // int solve(int n , vector<int> &dp){
    //     if(n<=1){
    //         return 1;
    //     }
    //     if(dp[n]!=-1){
    //         return dp[n];
    //     }
    //     int ans = 0;
    //     for(int i=1;i<=n;i++){
    //         ans+=solve(i-1 , dp)*solve(n-i , dp);
    //     }
    //     return dp[n] = ans;
    // }
    int numTrees(int n) 
  {
        int mod=1e9+7;
        vector<int>dp(n+1,0);
        dp[0]=1;
        dp[1]=1;
        for(int i=2;i<=n;i++)
        {
            for(int j=1;j<=i;j++)
            {
                dp[i]=(dp[i]+(1LL*dp[j-1]*dp[i-j])%mod)%mod;
            }
        }
        return dp[n];
    }
};

//{ Driver Code Starts.
#define mod (int)(1e9+7)
int main(){
    
    //taking total testcases
    int t;
    cin>>t;
    while(t--){
        
        //taking total number of elements
        int n;
        cin>>n;
        Solution ob;
        //calling function numTrees()
        cout<<ob.numTrees(n)<<"\n";
    }
}	
// } Driver Code Ends