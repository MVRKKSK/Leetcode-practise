//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    void solve(vector<vector<char>> &mat, vector<vector<int>> &visited, int i, int j, int n, int m) {
        static const vector<int> dr = {1, -1, 0, 0};
        static const vector<int> dc = {0, 0, 1, -1};
    
        queue<pair<int, int>> q;
        q.push({i, j});
        visited[i][j] = 1;
    
        while (!q.empty()) {
            auto current = q.front();
            q.pop();
    
            for (int k = 0; k < 4; ++k) {
                int ni = current.first + dr[k];
                int nj = current.second + dc[k];
    
                if (ni >= 0 && ni < n && nj >= 0 && nj < m && !visited[ni][nj] && mat[ni][nj] == 'O') {
                    q.push({ni, nj});
                    visited[ni][nj] = 1;
                }
            }
        }
    }
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        vector<vector<int>> visited(n , vector<int> (m , 0));
        for(int i=0;i<n;i++){
            if(mat[i][0]=='O' && !visited[i][0]){
                solve(mat , visited , i , 0 , n , m);
            }
             if(mat[i][m-1]=='O' && !visited[i][m-1]){
                solve(mat , visited , i , m-1 , n , m);
            }
        }
        for(int j=0;j<m;j++){
            if(mat[0][j]=='O' && !visited[0][j]){
                solve(mat , visited , 0 , j , n , m);
            }
            if(mat[n-1][j]=='O' && !visited[n-1][j]){
                solve(mat , visited , n-1 , j , n , m);
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j] && mat[i][j]=='O'){
                    mat[i][j] = 'X';
                }
            }
        }
        return mat;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends