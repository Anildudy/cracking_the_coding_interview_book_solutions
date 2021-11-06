#include<bits/stdc++.h>
using namespace std;

int maxIdx(vector<int>&v, int a, int b, int c){
    int len = v.size();
    int a_value = a>=0 && a<len ? a_value = v[a]: a=INT_MIN;
    int b_value = b>=0 && b<len ? b_value = v[b]: b=INT_MIN;
    int c_value = c>=0 && c<len ? c_value = v[c]: c=INT_MIN;

    int m = max(a_value, max(b_value,c_value));
    if(m==a_value)
        return a;  
    else if(m==b_value)
        return b;
    else
        return c;
}

void sort_peak_value(vector<int>& v){
    for(int i=1; i<v.size(); i+=2){
        int big_index = maxIdx(v,i-1,i,i+1);
        if(big_index!=i){
            swap(v[i], v[big_index]);
        }
    }
}

int main(){
    vector<int> v = {5,3,1,2,3};
    sort_peak_value(v);
    for(int i=0; i<v.size(); i++)
        cout<<v[i]<<" ";
    cout<<"\n";
    return 0;
}