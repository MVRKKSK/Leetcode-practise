//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

    bool isSafe(int i ,int j , vector<vector<int>> &board , int n){
        //check for upper diagonal
        int trow = i;
        int tcol = j;
        while(i>=0 && j>=0){
            if(board[i][j]==1){
                return false;
            }
            i--;
            j--;
        }
        i = trow;
        j = tcol;
        //check for left row
        while(j>=0){
            if(board[i][j]==1){
                return false;
            }
            j--;
        }
        //check for lowr diagonal
        i = trow;
        j = tcol;
        
        while(i<n && j>=0){
            if(board[i][j]==1){
                return false;
            }
            j--;
            i++;
        }
        return true;
    }
    void solve(int j , vector<vector<int>> &board , vector<vector<int>> &ans , int n , vector<int> &temp){
        if(j==n){
            ans.push_back(temp);
            return;
        }
        for(int i=0;i<n;i++){
            if(isSafe(i , j , board , n)){
                temp.push_back(i+1);
                board[i][j] = 1;
                solve(j+1 , board , ans , n , temp);
                board[i][j] = 0;
                temp.pop_back();
            }
        }
    }
    vector<vector<int>> nQueen(int n) {
        vector<vector<int>> board(n, vector<int>(n, 0));
        vector<vector<int>> ans;
        vector<int> val;
        solve(0 , board  , ans, n , val);
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends