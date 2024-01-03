//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int dp[1001][1001];
    bool isPalindrome(string &s, int i, int j){
        if(i>=j)return true;
        while(i++<j--){
            if(s[i-1]!=s[j+1])
            return false;
        }
        return true;
    }
    int minPartition(string &s, int i, int j){
        if(i>=j)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        if(isPalindrome(s,i,j)) return 0;
        int mini = INT_MAX;
        for(int k =i;k<j;k++){
            mini = min(mini, (dp[i][k]!=-1?dp[i][k]:minPartition(s,i,k))+(dp[k+1][j]!=-1? dp[k+1][j]:minPartition(s,k+1,j))+1);
        }
        return dp[i][j]=mini;
    }
    int palindromicPartition(string str)
    {
        memset(dp,-1,sizeof(dp));
        return minPartition(str, 0, str.size()-1);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
// } Driver Code Ends