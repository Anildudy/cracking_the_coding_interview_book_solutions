#include<bits/stdc++.h>
using namespace std;

int swap(int n){
    return ((n&0xaaaaaaaa) >> 1) | ((n & 0x55555555)<<1); 
}

int main(){
    int n;
    cin>>n;
    cout<<swap(n)<<"\n";

    return 0;
}