//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int countMin(string str){
    //complete the function here
    int i;
        int n=str.length();
        vector<int> palin[n];
        for(i=0;i<n;i++)
        {
            palin[i].resize(n,0);
        }
        for(int gap=1;gap<n;gap++)
        {
            for(int j=0,i=gap;i<n;j++,i++)
            {
                if(str[i]==str[j])
                    palin[j][i]=palin[j+1][i-1];
                else
                    palin[j][i]=min( palin[j+1][i],palin[j][i-1] )+1;
            }
        }
        
        return palin[0][n-1];
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string str;
        cin >> str;
        Solution ob;
        cout << ob.countMin(str) << endl;
    }
return 0;
}


// } Driver Code Ends