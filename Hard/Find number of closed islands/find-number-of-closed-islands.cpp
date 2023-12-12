//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
    public:
    bool dfs(vector<vector<int>> &matrix, vector<vector<int>> &visited, int N, int M, int i, int j) {
        if (i < 0 || i >= N || j < 0 || j >= M) {
            return false;
        }
    
        if (matrix[i][j] == 0 || visited[i][j] == 1) {
            return true;
        }
    
        visited[i][j] = 1;
    
        bool right = dfs(matrix, visited, N, M, i, j + 1);
        bool left = dfs(matrix, visited, N, M, i, j - 1);
        bool up = dfs(matrix, visited, N, M, i - 1, j);
        bool down = dfs(matrix, visited, N, M, i + 1, j);
    
        return right && left && up && down;
    }
    int closedIslands(vector<vector<int>>& matrix, int N, int M) {
        vector<vector<int>> visited(N , vector<int>(M , 0));
        int count = 0;
        for(int i=1;i<N-1;i++){
            for(int j=1;j<M-1;j++){
                if((matrix[i][j]==1)&&(!visited[i][j])){
                    count+=dfs(matrix , visited , N , M , i , j);
                }
            }
        }
        return count;
    }
};

//{ Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
        int N, M;
        cin >> N >> M;
        vector<vector<int>>matrix(N, vector<int>(M, 0));
        for(int i=0; i<N; i++)
            for(int j=0; j<M; j++)
                cin >> matrix[i][j];
                
        Solution obj;
        int ans = obj.closedIslands(matrix, N, M);
        cout << ans << "\n";
    }
	
	return 0;
	
}


// } Driver Code Ends