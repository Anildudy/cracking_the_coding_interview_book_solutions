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

void createLevelLinkedList(node* root, vector<list<node*>> &lists, int level){
  if(root==NULL)
    return;

  if(lists.size() == level){
    list<node*> ls;
    lists.push_back(ls);
  }

  lists[level].push_back(root);
  //cout<<root->value;
  createLevelLinkedList(root->left, lists, level+1);
  createLevelLinkedList(root->right, lists, level+1);

}


int main(){

  node* root = new node(1);
  //cout<<root<<"\n";
  root->left = new node(2);
  root->right = new node(3);
  root->left->left = new node(4);
  root->right->right = new node(5);
  root->left->right = new node(6);

  vector<list<node*>> lists;
  // list<node*> ls;
  // lists.push_back(ls);
  // lists[0].push_front(root);
  // auto it = lists[0].begin();
  // node * n = *it;
  // cout<<(n->value)<<"\n";
  //cout<<lists.size();

  createLevelLinkedList(root,lists, 0);
  cout<<lists.size()<<"\n";
  for(int i=0; i<lists.size(); i++){
    for(auto lt = lists[i].begin(); lt!= lists[i].end(); lt++){

      node* root = *lt;
      cout<<root->value<<" ";
    }
    cout<<"\n";
  }


return 0;
}
