//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    void solve(int ki, int kj, int i, int j, vector<vector<int>> &board, int n, int steps, int &ans) {
        if (ki == i && kj == j) {
            ans = min(steps, ans);
            return;
        }
    
        if (ki < 0 || kj < 0 || ki >= n || kj >= n || board[ki][kj] == 1) {
            return;
         }
    
        board[ki][kj] = 1;
        solve(ki + 1, kj - 2, i, j, board, n, steps + 1, ans);
        solve(ki + 2, kj - 1, i, j, board, n, steps + 1, ans);
        solve(ki + 2, kj + 1, i, j, board, n, steps + 1, ans);
        solve(ki + 1, kj + 2, i, j, board, n, steps + 1, ans);
        solve(ki - 1, kj + 2, i, j, board, n, steps + 1, ans);
        solve(ki - 2, kj + 1, i, j, board, n, steps + 1, ans);
        solve(ki - 2, kj - 1, i, j, board, n, steps + 1, ans);
        solve(ki - 1, kj - 2, i, j, board, n, steps + 1, ans);
        board[ki][kj] = 0;
    }
    int minStepToReachTarget(vector<int>&KnightPos, vector<int>&TargetPos, int N){
    	    int rowJumps[] = {-2,-2,-1,-1,1,1,2,2};
    	    int colJumps[] = {1,-1,2,-2,2,-2,1,-1};
    	    
    	    vector<vector<int>> vis(N+1,vector<int>(N+1,0));
    	    int ans = 1e9;
    	    queue<pair<int,pair<int,int>>> q;
    	    vis[KnightPos[0]][KnightPos[1]] = 1;
    	    q.push({0,{KnightPos[0],KnightPos[1]}});
    	    while(!q.empty()) {
    	        int c = q.front().first;
    	        int i = q.front().second.first;
    	        int j = q.front().second.second;
    	        q.pop();
    	        
    	        if(i==TargetPos[0] && j==TargetPos[1]) ans = min(ans,c);
    	        else {
    	            for(int k=0;k<8;k++) {
        	            int nr = i + rowJumps[k];
        	            int nc = j + colJumps[k];
        	            
        	            if(nr>=1 && nr<=N && nc>=1 && nc<=N && !vis[nr][nc]) {
        	                q.push({c+1,{nr,nc}});
        	                vis[nr][nc]=1;
        	            }
        	        }
    	        }
    	    }
    	    return (ans==1e9)?-1:ans;
    	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends