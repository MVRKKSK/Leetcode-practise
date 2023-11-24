//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to find whether a path exists from the source to destination.
    bool is_Possible(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        vector<int> row = {-1 , 1 , 0 , 0};
        vector<int> col = {0 , 0 , -1 , 1};
        vector<vector<int>> visited( n , vector<int>(n , 0));
        queue<pair<int,int>> kyu;
        bool found = false;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    kyu.push({i , j});
                    visited[i][j] = 1;
                    break;
                }
            }
        }
        while(!kyu.empty()){
            auto it = kyu.front();
            int r = it.first;
            int c = it.second;
            kyu.pop();
            if(grid[r][c]==2){
                return true;
            }
            for(int i=0;i<4;i++){
                int nrow = r+row[i];
                int ncol = c+col[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<n && grid[nrow][ncol]!=0 && !visited[nrow][ncol]){
                    kyu.push({nrow , ncol});
                    visited[nrow][ncol] = 1;
                }
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		bool ans = obj.is_Possible(grid);
		cout << ((ans) ? "1\n" : "0\n");
	}
	return 0;
}
// } Driver Code Ends