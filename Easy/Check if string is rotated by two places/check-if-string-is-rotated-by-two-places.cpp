//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to check if a string can be obtained by rotating
    //another string by exactly 2 places.
    bool isRotated(string str1, string str2)
    {
        int n = str1.size();
        int m = str2.size();
        if(str2.length()!=str1.length()) return false;
        if(m<=2 && n<=2 ){
            if(str1==str2) return true;
            return false;
        }
        int cw = true;
        for(int i=0;i<str1.size()-2;i++){
            if(str1[i]!=str2[i+2]){
                cw = false;
                break;
            }
        }
        if(cw && str1[n-2]==str2[0] && str1[n-1]==str2[1]){
            return true;
        }
        int ac = true;
        for(int i=2;i<str1.size();i++){
            if(str1[i]!=str2[i-2]){
                ac = false;
                break;
            }
        }
        if(ac && str1[0]==str2[n-2] && str1[1]==str2[n-1]){
            return true;
        }
        return false;
    }

};


//{ Driver Code Starts.

int main() {
	
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		string b;
		cin>>s>>b;
		Solution obj;
		cout<<obj.isRotated(s,b)<<endl;
	}
	return 0;
}

// } Driver Code Ends