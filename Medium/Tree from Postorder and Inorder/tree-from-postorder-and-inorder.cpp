//{ Driver Code Starts
/* program to construct tree using inorder and postorder traversals */
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

/* This funtcion is here just to test buildTreeUtil() */
void preOrder(Node* node) {
    if (node == NULL) return;

    /* then print the data of node */
    printf("%d ", node->data);

    /* first recur on left child */
    preOrder(node->left);

    /* now recur on right child */
    preOrder(node->right);
}

Node* buildTree(int in[], int post[], int n);

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int in[n], post[n];
        for (int i = 0; i < n; i++) cin >> in[i];
        for (int i = 0; i < n; i++) cin >> post[i];
        Node* root = buildTree(in, post, n);
        preOrder(root);
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends


/* Tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/

//Function to return a tree created from postorder and inoreder traversals.
int ind;
int findIndex(int in[] , int l , int r , int val){
    for(int i=l;i<=r;i++){
        if(in[i]==val){
            return i;
        }
    }
    return -1;
}
Node * solve(int post[] , int in[] , int l , int r){
    if(ind<0 || l>r){
        return NULL;
    }
    Node * root = new Node(post[ind--]);
    // if(l==r){
    //     root->left = NULL;
    //     root->right = NULL;
    //     return root;
    // }
    int inRoot = findIndex(in , l , r , root->data);
    root->right = solve(post , in , inRoot+1 , r );
    root->left = solve(post , in , l , inRoot-1);
    return root;
}
Node *buildTree(int in[], int post[], int n) {
    ind = n-1;
    return solve(post , in , 0 , n-1);
}
