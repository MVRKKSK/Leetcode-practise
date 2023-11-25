//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
    int LongestBitonicSequence(vector<int>arr)
    {
        int n=arr.size();
        vector<int>dp1(n),dp2(n);
    for(int i=0;i<n;i++){
        int sum=0;
        for(int j=0;j<i;j++){
            if(arr[j]<arr[i]){
               sum=max(sum,dp1[j]);
            }
        }
        dp1[i]=1+sum;
    }
    for(int i=n-1;i>=0;i--){
        int sum=0;
        for(int j=n-1;j>i;j--){
            if(arr[i]>arr[j]){
                sum=max(sum,dp2[j]);
            }
        }
        dp2[i]=1+sum;
    }
    int ans=0;
    for(int i=0;i<n;i++){
        ans=max(ans,dp1[i]+dp2[i]-1);
    }
    return ans;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution ob;
		int ans = ob.LongestBitonicSequence(nums);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends