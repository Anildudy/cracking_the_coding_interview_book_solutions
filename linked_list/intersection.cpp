#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int value;
    node* next;
    node(int val){
        value = val;
        next = NULL:
    }
};

bool check_intersection(node* head1, node* head2){
    if(head1==NULL || head2==NULL)
        return false;

    node* tmp1 = head1;
    node* tmp2 = head2;
    int l1 = 1;
    int l2 = 1;
    while(tmp1->next!=NULL){
        l1++;
        tmp1 = tmp1->next;
    }
    while(tmp2->next!=NULL){
        l2++;
        tmp2 = tmp2->next;
    }

    if(tmp1!=tmp2)
        return false;

    node* shorter = l1<=l2?head1:head2;
    node* longer = l1<l2?head2:head1;

    int k = abs(l1-l2);
    while(k>0 && longer!=NULL){
        longer = longer->next;
        k--;
    }

    while(shorter!=longer){
        shorter = shorter->next;
        longer = longer->next;
    }

    return shorter;
}

int main(){
    
}