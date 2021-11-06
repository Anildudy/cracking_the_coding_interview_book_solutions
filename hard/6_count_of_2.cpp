#include<bits/stdc++.h>
using namespace std;

int count_of_2(int n){
    int cnt = 0;
    while(n>0){
        int tmp = n%10;
        if(tmp==2)
            cnt++;
        n /= 10;
    }
    return cnt;
}

int main(){
    int n; 
    cin>>n;
    int cnt = 0;
    for(int i=1; i<=n; i++){
        cnt += count_of_2(i);
    }
    cout<<cnt<<"\n";
}