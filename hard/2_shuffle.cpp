#include<bits/stdc++.h>
using namespace std;

void shuffle(vector<int>& v){
    for(int i=v.size()-1; i>0; i--){
        int rd = rand()%(i+1);
        swap(v[i],v[rd]);
    }
    return ;
}

void shuffle1(vector<int>& v){
    for(int i=0; i<v.size(); i++){
        int rnd = rand()%(i+1);
        swap(v[i],v[rnd]);
    }
    return;
}

int main(){
    vector<int>v;
    for(int i=1; i<=52; i++)
        v.push_back(i);
    shuffle1(v);
    for(auto i: v)
        cout<<i<<" ";
    cout<<"\n";

    return 0;
}