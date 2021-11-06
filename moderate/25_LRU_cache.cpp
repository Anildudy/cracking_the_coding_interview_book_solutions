#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    string value;
    int key;
    node* next;
    node* prev;
    node(string val,int k){
        value = val;
        key = k;
        prev = NULL;
    }
};

void evict_last(node** tail, map<int,node*>&mp){
    int key = (*tail)->key;
    node* tmp = *tail;
    (*tail) = tmp->prev;
    (*tail)->next = NULL;
    tmp->prev = NULL;
    mp.erase(key);
    return;
}

string retrieve(node** head,node** tail,int key, map<int,node*>&mp){
    node* tmp = mp[key];
    if(tmp->next==NULL){
        tmp->prev->next = NULL;
        *tail = tmp->prev;
    }
    else{
        tmp->prev->next = tmp->next;
        tmp->next->prev = tmp->prev;
    }
    tmp->prev = NULL;
    tmp->next = *head;
    (*head)->prev = tmp;
    *head = tmp;
    return mp[key]->value;
}

void insertion(node ** head,node** tail,string val,int key,map<int,node*>& mp){
    node* new_node = new node(val,key);
    mp[key] = new_node;
    if(*head==NULL){
        *head = new_node;
        *tail = new_node;
    }
    else{
    new_node->next = *head;
    (*head)->prev = new_node;
    *head = new_node;
    }
}

int main(){
    node* head,*tail;
    int max_size;
    cout<<"Enter the maximum size ";
    cin>>max_size;
    map<int, node*>mp;
    string s;
    while(1){
        cout<<"Enter i for insertion, r for retreive and e for exit ";
        cin>>s;
        if(s=="i"){
            int k;
            string v;
            cout<<"Enter key ";
            cin>>k;
            cout<<"Enter value ";
            cin>>v;
            insertion(&head,&tail,v,k,mp);
            cout<<"Successfully inserted "<<v<<"\n";
            if(mp.size()==max_size){
                evict_last(&tail,mp);
                cout<<"Evicted the last element as the size was full\n";
            }
        }
        else if(s=="r"){
            int k;
            cout<<"Enter key of element to retreive ";
            cin>>k;
            string st = retrieve(&head,&tail,k,mp);
            cout<<"retrieved value "<<st<<"\n";
        }
        else if(s=="e")
            break;
    }

    return 0;
}