//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
        //Function to find distance of nearest 1 in the grid for each cell.
    
    vector<vector<int>> nearest(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> row = {-1, 1, 0, 0};
        vector<int> col = {0, 0, -1, 1};
        queue<pair<pair<int, int>, int>> kyu;
        vector<vector<int>> ans(n, vector<int>(m, 0));
        vector<vector<int>> visited(n, vector<int>(m, 0));
    
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    kyu.push({{i, j}, 0});
                    visited[i][j] = 1;
                } else {
                    visited[i][j] = 0;
                }
            }
        }
    
        while (!kyu.empty()) {
            auto it = kyu.front();
            int r = it.first.first;
            int c = it.first.second;
            int d = it.second;
            ans[r][c] = d;
            kyu.pop();
    
            for (int i = 0; i < 4; i++) {
                int nrow = r + row[i];
                int ncol = c + col[i];
                if (nrow >= 0 && nrow < n && ncol < m && ncol >= 0 && !visited[nrow][ncol]) {
                    visited[nrow][ncol] = 1;
                    kyu.push({{nrow, ncol}, d + 1});
                }
            }
        }
    
        return ans;
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
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends