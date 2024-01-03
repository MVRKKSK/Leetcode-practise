//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000


// } Driver Code Ends
/*You are required to complete this method*/
int pre[MAX];
class Solution{
    public:
     int maxAreaInHistograph( int arr[] , int n  )
    {
        stack<int>stk;
        
        int res=0;
        for(int i=0 ; i<n ; i++)
        {
            while(stk.empty()==false && arr[i]<=arr[stk.top()])
            {
                int top=stk.top();
                stk.pop();
                
                int curr=arr[top]*(stk.empty()?i:i-stk.top()-1);
                res=max(res,curr);
            }
            stk.push(i);
        }
        
        while(stk.empty()==false)
        {
            int top=stk.top();
            stk.pop();
            
            int curr=arr[top]*(stk.empty()?n:n-stk.top()-1);
            res=max(res,curr);
        }
        
        return res;
    }
    int maxArea(int M[MAX][MAX], int n, int m) {
        // Your code here
        
        int res=maxAreaInHistograph(M[0],m);
        
        for(int i=1 ; i<n ; i++)
        {
            for(int j=0 ; j<m ; j++)
            {
                if(M[i][j]==1)
                {
                    M[i][j]+=M[i-1][j];
                }
            }
            
            int currres=maxAreaInHistograph(M[i],m);
            res=max(res,currres);
        }
        return res;
    }
};


//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}

// } Driver Code Ends