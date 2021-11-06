#include<bits/stdc++.h>
using namespace std;

int add(int a, int b){
    while(b!=0){
        int tmp = a&b;
        a = a^b;
        b = (unsigned)tmp<<1;  //very large number can go out of order
    }
    return a;
}

int main(){
    int a,b;
    cin>>a>>b;
    cout<<add(a,b)<<"\n";

    return 0;
}