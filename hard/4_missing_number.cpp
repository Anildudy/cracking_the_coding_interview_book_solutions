#include<bits/stdc++.h>
using namespace std;
// Only Sample code if we are provided with a fetch method to fetch any bit and bit integers

int find_missing(vector<bit>&v, int col){
    if(col>=bit.size())   //when we have visited all the bits possible 
        return 0;
    vector<bit>zero_bit(v.size()/2);
    vector<bit>one_bit(v.size()/2);

    for( Bit t: v){
        if(t.fetch(col)==0)
            zero_bit.push_back(t);
        else
            one_bit.push_back(t);
    }

    if(zero_bit.size()<=one_bit.size()){
        int f  = find_missing(zero_bit,col+1);
        return (f<<1)|0;
    }
    else{
        int f = find_missing(one_bit, col+1);
        return (f<<1)|0;
    }
}

int main(){
    vector<bit>v;
    Bit v = find_missing(v,0);

    return 0;
}