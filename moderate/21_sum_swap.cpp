#include<bits/stdc++.h>
using namespace std;

vector<int> value(vector<int>&v1, vector<int>&v2){
    int sm1 = 0;
    int sm2 = 0;
    unordered_set<int>s;
    vector<int>v;
    for(int i=0; i<v1.size(); i++)
        sm1 += v1[i];
    for(int i=0; i<v2.size(); i++){
        sm2 += v2[i];
        s.insert(v2[i]);
    }
    int target;
    if((sm1-sm2)%2!=0)
        return v;
    else
        target = (sm1-sm2)/2;

    for(int i=0; i<v1.size(); i++){
        int a = v1[i];
        int b = a-target;
        if(s.find(b)==s.end())
            continue;
        else{
            v = {a,b};
            return v;
        }
    }
    return v;
}

int main(){
    int a,b;
    cin>>a>>b;
    vector<int>v1(a);
    vector<int>v2(b);
    for(int i=0; i<a; i++)
        cin>>v1[i];
    for(int i=0; i<b; i++)
        cin>>v2[i];

    vector<int>v = value(v1,v2);
    if(v.size()==0)
        cout<<"No pair found!\n";
    else{
        cout<<v[0]<<" "<<v[1]<<"\n";
    }

    return 0;
}