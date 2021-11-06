#include<bits/stdc++.h>
using namespace std;

class node {
public:
  int value;
  node * next;
};

node * k_from_last(node* head, int k){
  node * first = head;
  node * second = head;
  while(k--){
    if(second->next == NULL)
      return NULL;
    second = second->next;
  }
  while(second->next != NULL){
    first = first->next;
    second = second->next;
  }
  return first;
}

void push(node** head, int value){
  node* new_node = new node();
  node* tmp = *head;
  new_node->value = value;
  new_node->next = NULL;
  if(*head==NULL){
    *head = new_node;
    return;
  }
  while(tmp->next != NULL)
      tmp = tmp->next;
      tmp->next = new_node;
}

int main(){
  node * head= NULL;
  int val = 5;
  while(val--){
    int v;
    cin>>v;
    push(&head,v);
  }
  node * k_node = k_from_last(head,3);
  cout<<k_node->value<<"\n";
}
