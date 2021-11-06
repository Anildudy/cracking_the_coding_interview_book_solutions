#include<bits/stdc++.h>
using namespace std;

int multiply(int a, int b){
    if(b==0)
        return 0;
    return a + multiply(a,b-1);
}

int minProd(int smaller, int bigger){
    if(smaller==0)
        return 0;
    else if(smaller == 1)
        return bigger;

    int s = smaller>>1;
    int half_product = minProd(s,bigger);
    //cout<<half_product<<" ";
    if(smaller%2==0)
        return half_product+half_product;
    else
        return half_product+half_product+bigger;
}

int minProduct(int a, int b){
    int smaller = a>b?b:a; // Just for easily understading otherwise it's not necessary
    int bigger = a>b?a:b;
    cout<<smaller<<" "<<bigger<<"\n";
    return minProduct(smaller , bigger);
}

int main(){
    int a,b;
    cin>>a>>b;
    cout<<minProd(a,b)<<"\n";

    return 0;
}