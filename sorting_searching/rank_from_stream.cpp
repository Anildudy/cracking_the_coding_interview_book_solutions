#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    node* left;
    node* right;
    int value;
    int left_size = 0;
    node(int v){
        value = v;
    }
};

int get_rank(node* root, int target){
    if(root->value == target){
        return root->left_size;
    }
    else if(root->value > target){
        if(root->left == NULL)
            return -1;
        else
            return get_rank(root->left, target);
    }
    else{
        int right_rank = root->right==NULL ? -1:get_rank(root->right, target);
        if(right_rank==-1)
            return -1;
        else
            return root->left_size + 1+right_rank;
    }
}

void insert(node* root, int value){
    if(root->value>=value){
        if(root->left!=NULL)
            insert(root->left, value);
        else
            root->left = new node(value);
        root->left_size++;
    }
    else{
        if(root->right!=NULL)
            insert(root->right, value);
        else
            root->right = new node(value);
    }
}


int main(){
    int input;
    node* root = NULL;
    while(cin>>input){
        if(input == 0)
            break;
        else
            if(root==NULL){
                root = new node(input);
            }
            else{
                insert(root, input);
            }
    }

    // while(root!=NULL){
    //     cout<<root->value<<" ";
    //     root = root->left;
    // }
    cout<<get_rank(root, target)
    return 0;
}