//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to find length of longest increasing subsequence.
    int binary_search(vector<int> &res , int start , int end , int ele){
        while(start<=end){
            int mid = (start+end)/2;
            if(res[mid]<ele){
                start = mid+1;
            }
            else{
                end = mid-1;
            }
        }
        return start;
    }
    int solve(int arr[] , vector<int> &res , int n){
        for(int i=0;i<n;i++){
            if(res.size()==0){
                res.push_back(arr[i]);
            }
            if(res.back()<arr[i]){
                res.push_back(arr[i]);
            }
            else{
                int pos = binary_search(res , 0 , res.size()-1 , arr[i]);
                res[pos] = arr[i];
            }
        }
        return res.size();
    }
    int longestSubsequence(int n, int a[])
    {
        vector<int> res;
        return solve(a , res , n);
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}

// } Driver Code Ends