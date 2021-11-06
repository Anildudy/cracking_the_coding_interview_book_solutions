#include<bits/stdc++.h>
using namespace std;

int flip_bit(int a){
    return 1^a;
}

int sign(int a){
    return flip_bit((a>>31)&(0x1));
}

int main(){
    int a,b;
    cin>>a>>b;
    int sa = sign(a);
    int sb = sign(b);
    int s  = sign(a-b);
    int use_a = sa^sb;
    int use_s = flip_bit(sa^sb);

    int k = sa*use_a + s*use_s;
    int q = flip_bit(k);
    cout<<a*k+b*q<<"\n";

    return 0;
}