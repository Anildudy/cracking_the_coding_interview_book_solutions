#include<bits/stdc++.h>
using namespace std;

int conversion(int a, int b){
    int count = 0;
    while(a!=0 && b!=0){
        if((a&1) != (b&1))
            count++;
        int x = a&1;
        int y = b&1;
        cout<<x<<" "<<y<<"\n";
        a >>= 1;
        b >>= 1;
    }
    //cout<<count<<"\n";
    while(a!=0){
        if(a&1 == 1)
            count++;
        a >>= 1;
    }
    while(b!=0){
        if(b&1 == 1)
            count++;
        b >>= 1;
    }

    return count;
}

int usingXor(int a, int b){
    int count = 0;
    for(int i = a^b; i!=0; i = i&(i-1)){
        count++;
    }
    return count;
}

int main(){
    int a,b;
    cin>>a>>b;
    //cout<<conversion(a,b)<<"\n";
    cout<<usingXor(a,b)<<"\n";
    return 0;
}