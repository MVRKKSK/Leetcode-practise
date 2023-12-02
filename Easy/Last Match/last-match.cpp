//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    void getLPS(vector<int> &res , int m , string &B){
        int len = 0;
        res[0] = 0;
        int i = 1;
        while(i<m){
            if(B[i]==B[len]){
                len++;
                res[i] = len;
                i++;
            }
            else if(len!=0){
                len = res[len -1 ];
            }
            else{
                res[i] = 0;
                i++;
            }
        }
    }
    int findLastOccurence(string A,string B){
        int n = A.length();
        int m = B.length();
        vector<int> res(m, 0);  
        getLPS(res, m, B);
        int i = 0;
        int j = 0;
        int lastOccurrence = -1; 
        while (i < n) {
            if (A[i] == B[j]) {
                i++;
                j++;
            }
            if (j == m) {
                lastOccurrence = i - j+1; 
                j = res[j - 1];
            } else if (i < n && A[i] != B[j]) {
                if (j != 0) {
                    j = res[j - 1];
                } else {
                    i++;
                }
            }
        }
        return lastOccurrence;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string A,B;
        cin>>A>>B;
        Solution ob;
        cout<<ob.findLastOccurence(A,B)<<"\n";
        
    } 
    return 0; 
}
// } Driver Code Ends