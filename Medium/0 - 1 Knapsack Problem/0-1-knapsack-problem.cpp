//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int solve(int W , int wt[] , int val[] , int i , int n){
        if(i==0){
            return 0;
        }
        int op1 , op2=0;
        op1 = solve(W , wt , val , i-1 , n);
        if(W>=wt[i]){
            op2 = val[i] + solve(W-wt[i] , wt , val , i-1 , n);
        }
        return max(op1 , op2);
    }
    int knapSack(int W, int wt[], int val[], int n) {
        vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));
        for (int i = 1; i <= n; i++) {
            for (int w = 0; w <= W; w++) {
                if (w == 0) {
                    dp[i][w] = 0;
                    continue;
                }
                int op1 = INT_MIN;
                if (w >= wt[i - 1]) {
                    op1 = val[i - 1] + dp[i - 1][w - wt[i - 1]];
                }
                int op2 = dp[i - 1][w];
                dp[i][w] = max(op1, op2);
            }
        }
        return dp[n][W];
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends