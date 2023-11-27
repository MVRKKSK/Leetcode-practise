//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    bool solve(string &a , string &b , string &c , int i ,int j , int k , vector<vector<int>> &dp){
        if(k==0){
            return true;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int op1 = 0 , op2 = 0;
        if(i-1>=0 && a[i-1]==c[k-1]) op1 = solve(a , b , c , i-1 , j , k-1 , dp);
        if(j-1>=0 && b[j-1]==c[k-1]) op2 = solve(a, b , c , i , j-1 , k-1 , dp);
        return dp[i][j]= op1 || op2;
    }
    bool isInterleave(string a, string b, string c) 
    {
        // string s1 = A + B;
        if(c.length()!=a.length()+b.length()){
            return false;
        }
        vector<vector<int>>dp(a.length()+1 , vector<int>(b.length()+1 , -1));
        return solve(a, b , c , a.length() , b.length() , c.length() , dp);
    }

};

//{ Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
		string a,b,c;
		cin>>a;
		cin>>b;
		cin>>c;
		Solution obj;
		cout<<obj.isInterleave(a,b,c)<<endl;
	}
	// your code goes here
	return 0;
}
// } Driver Code Ends