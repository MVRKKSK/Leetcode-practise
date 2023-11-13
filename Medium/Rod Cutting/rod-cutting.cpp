//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    // int solve(int price[] , int i , int n){
    //     if(i==0){
    //         return price[i]*n;
    //     }
    //     int take = 0 + solve(price , i-1 , n);
    //     int notTake = INT_MIN;
    //     int rodLen = i+1;
    //     if(rodLen<=n){
    //         notTake = price[i] + solve(price , i , n-rodLen);
    //     }
    //     return max(take , notTake);
    // }
    int cutRod(int price[], int n) {
        // return solve(price , n-1 , n);
        vector<vector<int>> dp(n , vector<int>(n+1 , 0));
        for(int i=0;i<=n;i++){
            dp[0][i] = price[0]*i;
        }
        for(int i=1;i<n;i++){
            for(int j =0;j<=n;j++){
                int take = 0 + dp[i-1][j];
                int notTake = INT_MIN;
                int rodLen = i+1;
                if(rodLen<=j){
                    notTake = price[i]+dp[i][j-rodLen];
                }
                dp[i][j] = max(take , notTake);
            }
        }
        return dp[n-1][n];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends