#include<bits/stdc++.h>
using namespace std;

int max_sum(vector<int>& v){
    int mx_sum = INT_MIN;
    int curr_sum = 0;

    for(int i=1; i<v.size(); i++){
        curr_sum += v[i];
        mx_sum = max(curr_sum,mx_sum);
        if(curr_sum<0)
            curr_sum = 0;
    }
    return mx_sum;
}

int main(){
    vector<int> v;
    int a;
    while(1){
        cin>>a;
        if(a==-1)
            break;
        else
            v.push_back(a);
    }

    cout<<max_sum(v)<<"\n";

    return 0;
}