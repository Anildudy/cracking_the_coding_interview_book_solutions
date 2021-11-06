#include<bits/stdc++.h>
using namespace std;

class node {
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

int last_val=INT_MIN;

bool validate(node* root){ //cannot handle equal values
    if(root==NULL)
        return true;
    
    if(!validate(root->left))
        return false;
    
    if(last_val!=INT_MIN && root->value<=last_val)
        return false;
    last_val = root->value;

    if(!validate(root->right))
        return false;
    return true;
}

bool check_bst(node* root, node* min_node, node* max_node){
    if(root == NULL)
        return true;

    if((min_node && root->value<=min_node->value) || (max_node && root->value>=max_node->value)){
        return false;
    }
    if(!check_bst(root->left,min_node,root) || !check_bst(root->right, root, max_node))
        return false;

    return true;
}

int main(){

    node* root = new node(5);
  root->left = new node(4);
  root->right = new node(8);
  root->left->left = new node(3);
  root->right->right = new node(10);
  root->left->right = new node(4);
   root->right->right->left = new node(9);

    if(check_bst(root, NULL, NULL))
        cout<<"Not a BST\n";
    else
        cout<<"It's a binary search tree\n";
    
    return 0;
}