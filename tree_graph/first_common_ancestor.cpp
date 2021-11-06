#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int value;
    node* left;
    node* right;
    node(int val){
        value = val;
        left = NULL;
        right = NULL;
    }
};

node* first_common_ancestor(node* root,node* p ,node* q){
    if(root==NULL || root==p || root==q){
        return root;
    }
    node* left = first_common_ancestor(root->left,p,q);
    node* right = first_common_ancestor(root->right, p,q);

    if(left==NULL && right==NULL)
        return NULL;
    if(left!=NULL && right!=NULL)
        return root;
    return left==NULL?right:left;
}

int main(){
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    node* p = root->left;
    node* q = root->right;

    cout<<first_common_ancestor(root,p,q)->value<<"\n";
       
    return 0;
}