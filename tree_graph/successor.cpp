#include<bits/stdc++.h>
using namespace std;


TreeNode* left_most_child(TreeNode* n){
        if(n==NULL)
            return NULL;
        while(n->left !=NULL)
            n = n->left;
        return n;
}

TreeNode* find_successor(TreeNode* n){
    if(n==NULL)
        return NULL;
    
    if(n->right != NULL){
        return left_most_child(n->right);
    }
    else{
        TreeNode* q = n;
        TreeNode* x = q.parent;

        while(x!=NULL || x->left!=q){
            q = x;
            x = x->parent;
        }
        return x;
    }
}

int main(){

}