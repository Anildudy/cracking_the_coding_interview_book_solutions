#include<bits/stdc++.h>
using namespace std;

vector<int> random_set(vector<int>& v, int k){
    vector<int> res(k);
    for(int i=0; i<k; i++){
        res[i] = v[i];
    }
    for(int i=k; i<v.size(); i++){
        int rd = rand()%(i+1);
        if(rd<k)
            res[rd] = v[i];
    }
    return res;
}

int main(){
    vector<int>v;
    for(int i=1; i<=20; i++)
        v.push_back(i);
    vector<int>res = random_set(v,10);
    for(int i: res)
        cout<<i<<" ";
    cout<<"\n";

    return 0;
}