#include<bits/stdc++.h>
using namespace std;

class tNode {
public:
  int value;
  tNode* left;
  tNode* right;
};

tNode* new_node(int value){
  tNode* node = new tNode();
  node->value = value;
  node->left = NULL;
  node->right = NULL;

  return node;
}

tNode* minimal_tree(int arr[], int l, int r){
  if(l>r)
    return NULL;

  int mid = (l+r)/2;
  tNode* root = new_node(arr[mid]);

  root->left = minimal_tree(arr,l,mid-1);
  root->right = minimal_tree(arr,mid+1,r);

  return root;
}

void pre_order(tNode* root){
  if(root == NULL)
    return;
  cout<<root->value<<" ";
  pre_order(root->left);
  pre_order(root->right);
}

int main(){

int arr[] = {1,2,3,4,5};
int n = sizeof(arr)/sizeof(arr[0]);

tNode* root = minimal_tree(arr,0,n-1);
pre_order(root);

  return 0;
}
