//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	    int mod = 1e9+7;
	    int solve(vector<int> &dp , int i , int n){
	        if(i==n){
	            return 1;
	        }
	        if(i>n){
	            return 0;
	        }
	        if(dp[i]!=-1){
	            return dp[i];
	        }
	        int op1 , op2;
	        op1 = solve(dp , i+1 , n);
	        op2 = solve(dp , i+2 , n);
	        return dp[i] = (op1+op2)%mod;
	    }
		int nthPoint(int n){
		    // Code here
		    vector<int> dp(n+1 , -1);
		    return solve(dp , 0 , n);
		    
		}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		int ans  = ob.nthPoint(n);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends