#include<bits/stdc++.h>
using namespace std;

void find_diff(vector<char>& v, vector<int>& diff){
    int d = 0;
    for(int i=0; i<v.size(); i++){
        if(isdigit(v[i])){
            d--;
        }
        else{
            d++;
        }
        diff[i] = d;
    }
    return;
}

void find_longest_match(vector<int>&diff, vector<int>& match){
    map<int,int>mp;
    mp[0] = -1;
    for(int i=0; i<diff.size(); i++){
        if(mp.find(diff[i])==mp.end()){
            mp[diff[i]] = i;
        }
        else{
            int idx = mp[diff[i]];
            int dist = i-idx;
            int longest = match[0]-match[1];
            if(dist>longest){
                match[0] = idx;
                match[1] = i;
            }
        }
    }
    return ;
}

vector<char> find_longest_subarray(vector<char>& v ){
    vector<int>diff(v.size()); 
    find_diff(v,diff);
    vector<int>match(2,0);
    find_longest_match(diff,match);
    vector<char>res;
    for(int i=match[0]+1; i<=match[1]; i++)
        res.push_back(v[i]);

    return res;
}

int main(){
    vector<char>v = {'a','5','a','1','a','3','a','a','5','8','a'};
    vector<char> res = find_longest_subarray(v);

    for(auto item: res)
        cout<<item<<" ";
    cout<<"\n";

    return 0;
}