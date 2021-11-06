#include<bits/stdc++.h>
using namespace std;

class node {
public:
  int value;
  node* next;
};

// This method is when we declare a new_linked list

 /*node* remove_duplicate(node * head){
   if(head == NULL || head->next == NULL)
      return head;

      node* new_node = new node();
      new_node->value = head->value;
      node* n_head = new_node;
      head = head->next;
      while(head != NULL){
        node * tp = n_head;
        int c = 0;
        while(tp != NULL){
          if(head->value == tp->value){
            c++;
            break;
          }
          tp = tp->next;
        }

        if(c>0){
          head = head->next;
          break;
        }

        node* n_node = new node();
        n_node->value = head->value;
        new_node->next = n_node;
        new_node = new_node->next;
        head = head->next;
      }
      return n_head;
 }*/

node* remove_duplicate(node * head){
  if(head == NULL || head->next == NULL)
      return head;

  unordered_set<int> s;
  node* tmp = head;
  s.insert(tmp->value);
  tmp = tmp->next;
  node * prev = head;

  while(tmp != NULL){
    if(s.find(tmp->value) == s.end()){
      s.insert(tmp->value);
      tmp = tmp->next;
      prev = prev->next;
    }
    else{
      tmp = tmp->next;
      prev->next = tmp;
    }
  }
  return head;
}

int main(){
  node* head = new node();
  head->value = 2;
  int s=5;
  node * t = head;

  while(s--){
    int a;
    cin>>a;
    node* temp = new node();
    temp->value = a;
    t->next = temp;
    t = t->next;
  }

  t = remove_duplicate(head);
  while(t != NULL){
    cout<<t->value<<" ";
    t = t->next;
  }
  cout<<"\n";

  return 0;
}
