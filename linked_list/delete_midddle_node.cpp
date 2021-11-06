#include<bits/stdc++.h>
using namespace std;

class node{
public:
  int val;
  node* next;
};

void delete_node(node * target){
  while(target->next->next !=NULL ){
    target->val = target->next->val;
    target = target->next;
  }
  target->val = target->next->val;
  target->next = NULL;
}

void push(node** head, int val){
  node* new_node = new node();
  node* temp = *head;
  new_node->val = val;
  new_node->next = NULL;
  if(*head == NULL){
    *head = new_node;
    return;
  }
  while(temp->next != NULL)
    temp = temp->next;
  temp->next = new_node;
  return;
}

int main(){
  node* head = NULL;
  int v;
  while(cin>>v){
    if(v==0)
      break;
    push(&head,v);
  }

  node * temp = head->next->next->next;
  delete_node(temp);

  while(head!=NULL){
    cout<<head->val<<" ";
    head = head->next;
  }

return 0;
}
