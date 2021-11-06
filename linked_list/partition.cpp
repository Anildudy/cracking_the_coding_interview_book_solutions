#include<bits/stdc++.h>
using namespace std;

class node {
public:
  int value;
  node* next;
  node(int val){
    value = val;
  }
};

node* partition(node* head, int val){
  if(head == NULL)
    return NULL;

  node* ptr = head;
  //cout<<ptr->value<<" ";
  while(ptr->next != NULL){
    if(ptr->next->value < val){
      node* disp = ptr->next;
      ptr->next = disp->next;
      disp->next = head;
      head = disp;
      continue;
    }
    ptr = ptr->next;
  }
  // while(head!=NULL){
  //   cout<<head->value<<" ";
  //   head = head->next;
  // }
  return head;
}

void push(node** head, int value){
  node* new_node = new node(value);
  new_node->next = *head;
  *head = new_node;
}

int main(){
  node* head=NULL;
  int val;
  cin>>val;
  int input;
  while(cin>>input){
    if(input == 0)
      break;
    //cout<<input<<" ";
    push(&head, input);
    //cout<<head->value<<" ";
  }
  head = partition(head, val);
  while(head!=NULL){
    cout<<head->value<<" ";
    head = head->next;
  }
  return 0;
}
