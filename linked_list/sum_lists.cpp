#include<bits/stdc++.h>
using namespace std;

class node{
public:
  int value;
  node* next;
  node(int val){
    value = val;
  }
};

node* sum_lists(node* l1, node* l2){
  node* res, *res_head;
  int sum, carry=0;
  sum = l1->value+l2->value;
  carry = sum/10;
  node* new_node = new node(sum%10);
  res_head = new_node;
  //cout<<res_head->value<<endl;
  res = res_head;
  //cout<<res->value<<endl;
  l1 = l1->next;
  l2 = l2->next;
  //cout<<res_head->value<<" ";
  while(l1!=NULL && l2!=NULL){
    sum = l1->value+ l2->value + carry;
    node* new_node = new node(sum%10);
    res->next = new_node;
    res = res->next;
    carry = sum/10;
    l1 = l1->next;
    l2 = l2->next;
  }

  while(l1!=NULL){
    sum = l1->value+ carry;
    node* new_node = new node(sum%10);
    res->next = new_node;
    res = res->next;
    carry = sum/10;
    l1 = l1->next;
  }

  while(l1!=NULL){
    sum = l2->value+ carry;
    node* new_node = new node(sum%10);
    res->next = new_node;
    res = res->next;
    carry = sum/10;
    l2 = l2->next;
  }

  return res_head;
}



void push(node** head, int value){
  node* new_node = new node(value);
  new_node->next = *head;
  *head = new_node;
}

int main(){
  node* l1=NULL, *l2=NULL;
  int input;
  while(cin>>input){
    if(input==0)
      break;
    push(&l1, input);
  }
  while(cin>>input){
    if(input==0)
      break;
    push(&l2,input);
  }

  node* hd = sum_lists(l1, l2);
  while(hd!=NULL){
    cout<<hd->value<<" ";
    hd = hd->next;
  }

  return 0;
}
