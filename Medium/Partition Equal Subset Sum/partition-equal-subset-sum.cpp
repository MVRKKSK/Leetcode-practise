//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    // bool solve(int i, int arr[], int sum) {
    //     if (i < 0 || sum < 0) {
    //         return false;
    //     }
    //     if (sum == 0) {
    //         return true;
    //     }
    //     bool take = solve(i - 1, arr, sum - arr[i]);
    //     bool notTake = solve(i - 1, arr, sum);
    //     return take || notTake;
    // }
    
    int equalPartition(int N, int arr[]) {
        int sum = 0;
        for (int i = 0; i < N; i++) {
            sum += arr[i];
        }
        if (sum % 2 != 0) {
            return false; 
        }
        sum=sum/2;
        vector<int> prev(sum+1 , false) , curr(sum+1 , false);
        prev[0] = curr[0] = true;
        if(arr[0]<=sum) prev[arr[0]] = true;
        for(int i=1;i<N;i++){
            for(int j=1;j<=sum;j++){
                bool notTake = prev[j];
                bool take = false;
                if(arr[i]<=j){
                    take = prev[j-arr[i]];
                }
                curr[j] = take || notTake;
            }
            prev = curr;
        }
        return prev[sum];
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends