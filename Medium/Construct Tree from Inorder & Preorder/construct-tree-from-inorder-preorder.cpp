//{ Driver Code Starts
//

#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

// } Driver Code Ends

/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution{
    public:
    int ind;
    // Node * solve(int pre[] , int preStart , int preEnd , int in[] , int inStart , int inEnd , map<int , int> mp){
    //     if((preStart>preEnd)||(inStart>inEnd)){
    //         return nullptr;
    //     }
    //     Node * root = new Node(pre[preStart]);
    //     int inRoot = mp[root->data];
    //     int numsLeft = inRoot-inStart;
    //     root->left = solve(pre , preStart+1 , preStart+numsLeft , in , inStart , inRoot-1 , mp);
    //     root->right = solve(pre , preStart+numsLeft+1 , preEnd , in , inRoot+1 , inEnd , mp);
    //     return root;
    // }
    int findIndex(int in[] , int l , int r , int ele){
        for(int i=l;i<=r;i++){
            if(in[i]==ele){
                return i;
            }
        }
        return -1;
    }
    Node * solve(int in[] , int pre[] , int l , int e ){
        if(l>e){
            return nullptr;
        }
        Node * root = new Node(pre[ind++]);
        if(l==e){
            root->left = nullptr;
            root->right = nullptr;
            return root;
        }
        int inIndex = findIndex(in , l , e , root->data);
        root->left = solve(in , pre , l , inIndex-1);
        root->right = solve(in , pre , inIndex+1 , e);
        return root;
    }
    Node* buildTree(int in[],int pre[], int n)
    {
        // Code herema
        ind = 0;
        return solve(in , pre , 0 , n-1);
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
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		Solution obj;
		Node *root = obj.buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}

// } Driver Code Ends