//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
    void dfs(vector<vector<char>> &grid , vector<vector<bool>> &visited , int i , int j){
        int n = grid.size();
        int m = grid[0].size();
        if(i<0 || j<0 || i>n-1 || j>m-1 || visited[i][j] || grid[i][j]!='1'){
            return;
        }
        visited[i][j] = true;
        dfs(grid , visited , i+1 , j);
        dfs(grid , visited , i-1 , j);
        dfs(grid , visited , i , j-1);
        dfs(grid , visited , i , j+1);
        dfs(grid , visited , i-1 , j+1);
        dfs(grid , visited , i+1 , j+1);
        dfs(grid , visited , i-1 , j-1);
        dfs(grid , visited , i+1 , j-1);
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;
        vector<vector<bool>> visited(n , vector<bool>(m , false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j] && grid[i][j]=='1'){
                    dfs(grid , visited , i , j);
                    count++;
                }
            }
        }
        return count;

    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends