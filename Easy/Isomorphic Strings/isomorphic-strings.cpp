//{ Driver Code Starts
// C++ program to check if two strings are isomorphic


#include<bits/stdc++.h>


using namespace std;
#define MAX_CHARS 256

// } Driver Code Ends
class Solution
{
    public:
    //Function to check if two strings are isomorphic.
    bool areIsomorphic(string str1, string str2) {
    if (str1.length() != str2.length()) {
        return false;
    }

    unordered_map<char, char> st1;
    unordered_map<char, char> st2;

    for (int i = 0; i < str1.length(); i++) {
        char c1 = str1[i];
        char c2 = str2[i];

        if ((st1.find(c1) != st1.end() && st1[c1] != c2) || (st2.find(c2) != st2.end() && st2[c2] != c1)) {
            return false;
        }

        st1[c1] = c2;
        st2[c2] = c1;
    }

    return true;
}
};

//{ Driver Code Starts.

// Driver program
int main()
{
    int t;
    cin>>t;
    string s1,s2;
    while (t--) {
        cin>>s1;
        cin>>s2;
        Solution obj;
        cout<<obj.areIsomorphic(s1,s2)<<endl;
    }
    
    return 0;
}
// } Driver Code Ends