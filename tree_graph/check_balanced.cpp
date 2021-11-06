#include<bits/stdc++.h>
using namespace std;

class node {
    public:
    int value;
    node* left;
    node* right;

    node(int val){
        value = val;
    }
};

int check(node* root){
    if(root == NULL)
        return 0;

    int l = check(root->left);
    if(l==-1)
        return -1;
    int r = check(root->right);
    if(r==-1)
        return -1;

    if(abs(l-r)>1)
        return -1;
    
    return max(l,r)+1;
}

bool check_balanced(node* root){
    if(check(root)>0)
        return true;
    else 
        return false;
}


int main(){
  node* root = new node(1);
  root->left = new node(2);
  root->right = new node(3);
  root->left->left = new node(4);
  root->right->right = new node(5);
  root->left->right = new node(6);
   root->right->right->left = new node(7);
   //root->right->right->left->right = new node(8);
   if(check_balanced(root))
        cout<<"balanced"<<endl;
    else
        cout<<"Not balanced\n";

  return 0;
}