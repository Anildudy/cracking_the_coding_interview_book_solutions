#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int value;
    node* next;
    node(int val){
        value = val;
        next = NULL;
    }
};

bool recurse(node** left,node* right){
    if(right==NULL)
        return true;

    bool isp = recurse(left, right->next);
    if(isp == false)
        return false;
    
    bool isp1 = ((*left)->value == right->value);
    *left = (*left)->next;
    return isp1;
}

bool is_pallindrome(node* head){
    node* slow = head;
    node* fast = head;
    stack<int> st;

    while(fast!=NULL && fast->next!=NULL){
        st.push(slow->value);
        slow = slow->next;
        fast = fast->next->next;
    }
    if(fast!=NULL){
        slow = slow->next;
    }

    while(slow!=NULL){
        if(slow->value != st.top())
            return false;
        st.pop();
        slow = slow->next;
    }
    return true;
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

    // while(head!=NULL){
    //     cout<<head->value<<" ";
    //     head = head->next;
    // }
    if(recurse(&head, head))
        cout<<"It's a pallindrome\n";
    else
        cout<<"It's not a pallindrome\n";

    return 0;
}