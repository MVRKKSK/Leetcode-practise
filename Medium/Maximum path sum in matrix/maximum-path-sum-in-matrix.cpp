//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int maximumPath(int n, vector<vector<int>> matrix)
    {
        vector<vector<int>> dp(n+1 , vector<int>(n+1  , 0));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int up = i > 0 ? dp[i - 1][j] : 0;
                int ur = (i > 0 && j < n - 1) ? dp[i - 1][j + 1] : 0;
                int ul = (i > 0 && j > 0) ? dp[i - 1][j - 1] : 0;
                dp[i][j] = matrix[i][j] + max(up, max(ur, ul));
            }
        }
        int maxPath = 0;
        for (int j = 0; j < n; j++)
        {
            maxPath = max(maxPath, dp[n - 1][j]);
        }
    
        return maxPath;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}
// } Driver Code Ends