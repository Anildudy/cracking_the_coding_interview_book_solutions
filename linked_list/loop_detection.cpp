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

node* first_loop_node(node* head){
    node* slow = head;
    node* fast = head;

    while(fast!=NULL && fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
        //cout<<slow->value<<" "<<fast->value<<"\n";
        if(slow == fast)
            break;
    }

    if(fast==NULL || fast->next==NULL)
        return NULL;

    slow = head;
    //cout<<fast->value<<"\n";
    while(slow!=fast){
        slow = slow->next;
        fast = fast->next;
    }
    //cout<<slow->value<<"\n";
    return slow;
}

void push(node* head, int val){
    while(head->next != NULL){
        head = head->next;
    }
    node* new_node = new node(val);
    head->next = new_node;
}

int main(){
    node* head=NULL;
    int input;
    while(cin>>input){
        if(input==0) break;
        if(head==NULL){
            node* new_node = new node(input);
            head = new_node;
        }
        else{
            push(head, input);
        }
    }

    node* tmp = head;
    while(tmp->next!=NULL)
        tmp = tmp->next;

    tmp->next = head->next->next;
    //cout<<tmp->value<<"\n";
    cout<<first_loop_node(head)->value<<"\n";

    return 0;
}