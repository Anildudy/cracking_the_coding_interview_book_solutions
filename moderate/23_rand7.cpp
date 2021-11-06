#include<bits/stdc++.h>
using namespace std;

// Not exactly clear try again  
int rand5(){
    int no = rand()%5;
    //cout<<no<<" ";
    return no;
}

int rand7(){
    while(1){
        int no = 5*rand5() + rand5();
        if(no<21)
            return no%7;
    }
}

int main(){
    srand(time(0));
    cout<<rand7()<<"\n";

    return 0;
}