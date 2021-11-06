#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> get_subsets(vector<int> set, int index){
    vector<vector<int>> all_subsets;
    if(index == set.size()){
        all_subsets.push_back(vector<int>());
    }

    else{
        all_subsets = get_subsets(set, index+1);
        int val = set[index];
        vector<vector<int>> new_subsets;
        for(auto item : all_subsets){
            item.push_back(val);
            new_subsets.push_back(item);
        }

        for(auto item : new_subsets){
            all_subsets.push_back(item);
        }
    }
    return all_subsets;
}


int main(){
    vector<int> set = {1,2,3,4};
    int index = 0;
    vector<vector<int>> all_subsets = get_subsets(set, index);
    for(auto item: all_subsets){
        for(auto it: item){
            cout<<it<<" ";
        }
        cout<<"\n";
    }

    return 0;
}