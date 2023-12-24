//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int buyMaximumProducts(int n, int k, int price[]){
        //Write your code here
        vector<pair<int,int>> v(n);
        for(int i=0;i<n;i++){
            v[i].first = price[i];
            v[i].second = i+1;
        }
        sort(v.begin() , v.end());
        int count = 0;
        for(int i=0;i<n;i++){
            int quantity = k/v[i].first;
            quantity = min(quantity , v[i].second);
            count += quantity;
            k-=quantity*v[i].first;
        }
        return count;
    }
};


//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n, k;
	    cin >> n >> k;
	    int price[n];
	    for(int i = 0 ; i < n; i++){
	        cin >> price[i];
	    }
	    Solution ob;
	    int ans = ob.buyMaximumProducts(n, k, price);
	    cout << ans<<endl;
	}
	return 0;
}

// } Driver Code Ends