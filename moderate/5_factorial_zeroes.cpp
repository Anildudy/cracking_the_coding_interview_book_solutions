#include<bits/stdc++.h>
using namespace std;

int no_of_zeroes(int n){
    int count = 0;
    if(n<5)
        return 0;
    int i=5;
    while(i<=n){
        if(i%5==0){
            int k = i;
            while(k%5==0){
                count++;
                k /=5;
            }
        }
        i += 5;
    }
    return count;
}

int counting_multipes_method(int n){
    int count = 0;
    if(n<0)
        return -1;
    for(int i=5; i<=n; i*=5){
        count += n/i;
    }
    return count;
}

int main(){
    int n;
    cin>>n;
    cout<<no_of_zeroes(n)<<"\n";
    cout<<counting_multipes_method(n)<<"\n";
    
    return 0;
}