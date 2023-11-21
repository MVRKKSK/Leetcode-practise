//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find minimum time required to rot all oranges. 
    // int solve(vector<vector<int>> &grid , vector<vector<int>> &visited , int i , int j , int ans){
    //     int n = grid.size();
    //     int m = grid[0].size();
    //     if(i<0 || i>n || j<0 || j>m || grid[i][j]==0 || visited[i][j]){
    //         return 0;
    //     }
    //     if(grid[i][j]==1){
    //         grid[i][j] = 2;
            
    //     }
    // }
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visited(n , vector<int>(m , 0));
        queue<pair<pair<int,int> , int>> kyu;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    kyu.push({{i , j} , 0});
                    visited[i][j] = 2;
                }
                else{
                    visited[i][j] = 0;
                }
            }
        }
        int ans = INT_MIN;
        int trow[] = {-1 , 0 , 1 , 0};
        int tcol[] = {0 , 1 , 0 , -1};
        while(!kyu.empty()){
            int r = kyu.front().first.first;
            int c = kyu.front().first.second;
            int t = kyu.front().second;
            ans = max(ans , t);
            kyu.pop();
            for(int i=0;i<4;i++){
                int nrow = r+trow[i];
                int ncol = c+tcol[i];
                if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && visited[nrow][ncol]!=2 && grid[nrow][ncol]==1){
                    kyu.push({{nrow , ncol} , t+1});
                    visited[nrow][ncol] = 2;
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(visited[i][j]!=2 && grid[i][j]==1){
                    return -1;
                }
            }
        }
        return ans==INT_MIN ? 0 : ans;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends