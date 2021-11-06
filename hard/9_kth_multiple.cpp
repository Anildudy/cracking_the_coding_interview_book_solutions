#include<bits/stdc++.h>
using namespace std;

bool find_next(int n){
    if(n%2==0)
        return false;

    while(n!=1){
        if(n%3==0){
            n /= 3;
        }
        else if(n%5==0){
            n /=5;
        }
        else if(n%7==0){
            n /= 7;
        }
        else{
            return false;
        }
    }
    return true;
}

int main(){
    int k;
    cin>>k;
    vector<int>res;
    int i=1;
    while(res.size()!=k){
        if(find_next(i))
            res.push_back(i);
        i+=2;
    }

    for(auto item: res)
        cout<<item<<" ";
    cout<<"\n";

    return 0;
}