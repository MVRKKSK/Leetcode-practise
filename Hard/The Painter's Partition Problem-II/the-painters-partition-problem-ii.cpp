//{ Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    int count_students(long long boards, int arr[], int n) {
    int students = 1;
    long long total_boards = 0;
    for (int i = 0; i < n; i++) {
        if (total_boards + arr[i] <= boards) {
            total_boards += arr[i];
        } else {
            students++;
            total_boards = arr[i];
        }
    }
    return students;
}

long long minTime(int arr[], int n, int k) {
    long long high = 0;
    long long low = 0;
    long long ans = 0;

    // Calculate the total number of boards
    for (int i = 0; i < n; i++) {
        high += arr[i];
        low = std::max(static_cast<long long>(arr[i]), low);
    }

    while (low <= high) {
        long long mid = (low + high) / 2;
        long long students = count_students(mid, arr, n);
        if (students > k) {
            low = mid + 1;
        } else {
            ans = mid;
            high = mid - 1;
        }
    }
    return ans;
}
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int k,n;
		cin>>k>>n;
		
		int arr[n];
		for(int i=0;i<n;i++)
		    cin>>arr[i];
		Solution obj;
		cout << obj.minTime(arr, n, k) << endl;
	}
	return 0;
}
// } Driver Code Ends