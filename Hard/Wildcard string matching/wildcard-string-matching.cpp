//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution{
    public:
    bool match(string wild, string pattern)
    {
        int a=pattern.size();
        int b=wild.size();
        vector<vector<bool>> dp(a+1,vector<bool>(b+1,false));
        dp[0][0]=true;
        for(int j=1;j<=b;j++){
            if(wild[j-1]=='*' || wild[j-1]=='?'){
                dp[0][j]=dp[0][j-1];
            }
        }
        for(int i=1;i<=a;i++){
            for(int j=1;j<=b;j++){
                if(wild[j-1]==pattern[i-1] || wild[j-1]=='?'){
                    dp[i][j]=dp[i-1][j-1];
                }
                else {
                    if(wild[j-1]=='*'){
                      dp[i][j]=dp[i][j-1]||dp[i-1][j];
                    }
                }
            }
        }
        return dp[a][b];
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t-->0)
    {
        string wild, pattern;
        cin>>wild>>pattern;
        
        Solution ob;
        bool x=ob.match(wild, pattern);
        if(x)
        cout<<"Yes\n";
        else
        cout<<"No\n";
    }
    return 0;
}
// } Driver Code Ends