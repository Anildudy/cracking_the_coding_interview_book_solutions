#include<bits/stdc++.h>
using namespace std;

int negat(int a){
    int new_sign = a>0?-1:1;
    int neg = 0;
    int delta = new_sign;
    while(a!=0){
        bool diff_sign = (a+delta>0) != (a>0);
        if(a+delta!=0 && diff_sign)
            delta = new_sign;
        neg += delta;
        a += delta;
        delta += delta;
    }
    return neg;
}

int sub(int a, int b){
    int c = negat(b);
     return a+c;
}

int multiply(int a, int b){
    if(a<b)
        return multiply(b,a);
    int sum = 0;
    for(int i=abs(b); i>0; --i){
        sum += a;
    }
    if(b<0){
        sum = negat(sum);
    }
    return sum;
}

int divide(int a, int b){
    if(b==0)
        return -1;
    int absa = abs(a);
    int absb = abs(b);
    int product = 0;
    int x = 0;

    while(product+absb<=absa){
        product += absb;
        x++;
    }
    if((a<0 && b<0)|| (a>0 && b>0))
        return x;
    else
        return negat(x);
}

int main(){
    int a,b;
    cin>>a>>b;
    cout<<sub(a,b)<<"\n";
    cout<<multiply(a,b)<<"\n";
    cout<<divide(a,b)<<"\n";

    return 0;
}