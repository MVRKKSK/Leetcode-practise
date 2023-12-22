//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class Meet{
    public:
    int start , end , index;
    Meet(int s , int e , int i){
        this->start = s;
        this->end = e;
        this->index = i;
    }
};
class Solution{
public:
    
    vector<int> maxMeetings(int N,vector<int> &S,vector<int> &F){
        vector<Meet> meetings;
        for(int i=0;i<N;i++){
            meetings.push_back(Meet(S[i] , F[i] , i+1));
        }
        sort(meetings.begin() , meetings.end() , [](Meet &a , Meet&b){
            if(a.end==b.end){
                return a.index<b.index;
            }
            return a.end<b.end;
        });
        int listIndex = -1;
        vector<int> ans;
        for(int i=0;i<N;i++){
            if(meetings[i].start>listIndex){
                ans.push_back(meetings[i].index);
                listIndex = meetings[i].end;
            }
        }
        sort(ans.begin() , ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> S(n),F(n);
        for(int i=0;i<n;i++){
            cin>>S[i];
        }
        for(int i=0;i<n;i++){
            cin>>F[i];
        }
        Solution ob;
        vector<int> ans=ob.maxMeetings(n,S,F);
        for(int i=0;i<ans.size();i++){
            cout<<ans[i];
            if(i!=ans.size()-1){
                cout<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends