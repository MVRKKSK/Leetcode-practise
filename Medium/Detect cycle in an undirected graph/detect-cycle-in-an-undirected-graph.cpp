//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool solve(int V, vector<int> adj[], int src, vector<int> &visited) {
        vector<int> parent(V , -1);
        queue<int> kyu;
        kyu.push(src);
        visited[src] = 1;
        while (!kyu.empty()) {
            int node = kyu.front();
            kyu.pop();
            for (auto adjNode : adj[node]) {
                if (!visited[adjNode]) {
                    visited[adjNode] = 1;
                    kyu.push(adjNode);
                    parent[adjNode] = node;
                } else if (parent[node]!=adjNode) {
                    return true;
                }
            }
        }
        return false;
    }
    
    bool isCycle(int V, vector<int> adj[]) {
        int n = V;
        vector<int> visited(n, 0);
        for (int i = 0; i < n; i++) {
            if (!visited[i] && solve(V, adj, i, visited)) {
                return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends