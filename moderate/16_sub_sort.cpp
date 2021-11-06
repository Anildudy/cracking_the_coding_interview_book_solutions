#include<bits/stdc++.h>
using namespace std;

int find_end_left_subsequence(vector<int>&v){
    for(int i=1; i<v.size(); i++){
        if(v[i]<v[i-1])
            return i-1;
    }
    return v.size()-1;
}

int find_start_right_subsequence(vector<int>&v){
    for(int i=v.size()-2; i>=0; i--){
        if(v[i]>v[i+1])
            return i+1;
    }
    return 0;
}

int shrink_left(vector<int>&v, int min_index, int start){
    int comp = v[min_index];
    for(int i=start-1; i>=0; i--){ // No need to compare with start as next element will always be less so it will be always included
        if(v[i]<=comp)
            return i+1;
    }
    return 0;
}

int shrink_right(vector<int>&v, int max_index, int start){
    int comp = v[max_index];
    for(int i=start; i<v.size(); i++){
        if(v[i]>=comp)
            return i-1;
    }
    return v.size()-1;
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

    int end_left = find_end_left_subsequence(v);
    if(end_left>=v.size()-1)
        cout<<"already sorted\n";
    else{
        int start_right = find_start_right_subsequence(v);
        int max_index = end_left;
        int min_index = start_right;

        for(int i=end_left+1; i<start_right; i++){
            if(v[i]>v[max_index]) max_index = i;
            if(v[i]<v[min_index]) min_index = i;
        }

        int left = shrink_left(v,min_index, end_left);
        int right = shrink_right(v,max_index, start_right);
        cout<<left<<" "<<right<<"\n";
    }

    return 0;
}