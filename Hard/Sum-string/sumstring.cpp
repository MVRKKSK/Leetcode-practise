//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    string add(string s1 , string s2){
        int i = s1.length()-1;
        int j = s2.length()-1;
        int carry = 0;
        string res = "";
        while(i>=0 or j>=0 or carry){
            int sum = carry;
            if(i>=0){
                sum+=s1[i--]-'0';
            }
            if(j>=0){
                sum+=s2[j--]-'0';
            }
            int rem = sum%10;
            carry = sum/10;
            res.push_back(rem+'0');
        }
        reverse(res.begin() , res.end());
        // cout<<res<<endl;
        return res;
    }
    bool solve(string s , int start , int p1 , int p2 , int n){
        string s1 = s.substr(start , p1);
        string s2 = s.substr(start+p1 , p2);
        string s3 = add(s1 , s2);
        // cout<<s1<<" "<<s2<<" "<<s3<<endl;
        int len = s3.length();
        if(len>n-start-p1-p2){
            return false;
        }
        if(s3==s.substr(start+p1+p2 , len)){
            if(start+p1+p2+len==n){
                return true;
            }
            
            return solve(s , start+p1 , p2 , len , n);
        }
        return false;
    }
    bool isSumString(string & s){
        int n = s.size();
        for(int i=1;i<n;i++){
            for(int j=1;i+j<n;j++){
                if(solve(s , 0 , i , j , n)){
                    return 1;
                }
            }
        }
        return 0;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.isSumString(S) << endl;
    }
    return 0; 
} 

// } Driver Code Ends