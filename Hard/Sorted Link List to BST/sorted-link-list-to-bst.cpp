//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h> 
using namespace std; 

struct LNode
{
    int data;
    struct LNode* next;
    
    LNode(int x){
        data = x;
        next = NULL;
    }
};

struct TNode  
{  
    
    int data;  
    struct TNode* left;  
    struct TNode* right; 
    TNode(int x)
    {
        data=x;
        left=right=NULL;
    }
}; 

void preOrder(TNode* node)  
{  
    if (node == NULL)  
        return;  
    cout<<node->data<<" ";  
    preOrder(node->left);  
    preOrder(node->right);  
} 


// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
    TNode * solve(vector<int> &temp , int start , int end){
        if(start>end){
            return nullptr;
        }
        int mid = (start+end)/2;
        if((start+end)%2==1){
            mid++;
        }
        TNode * root = new TNode(temp[mid]);
        root->left = solve(temp , start , mid-1);
        root->right = solve(temp , mid+1 , end);
        return root;
    }
    TNode* sortedListToBST(LNode *head) {
        vector<int> temp;
        
        while(head){
            temp.push_back(head->data);
            head = head->next;
        }
        return solve(temp , 0 , temp.size()-1);
    }
};

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;

        int data;
        cin>>data;
        LNode *head = new LNode(data);
        LNode *tail = head;
        for (int i = 0; i < n-1; ++i)
        {
            cin>>data;
            tail->next = new LNode(data);
            tail = tail->next;
        }
        Solution ob;
        TNode* Thead = ob.sortedListToBST(head);
        preOrder(Thead);
        cout<<"\n";
        
    }
    return 0;
}

// } Driver Code Ends