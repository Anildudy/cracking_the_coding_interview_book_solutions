#include<bits/stdc++.h>
using namespace std;

int find_difference(vector<int>arr1, vector<int>arr2){
    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());

    int min_diff = INT_MAX;
    int i=0, j=0;
    while(i<arr1.size() && j<arr2.size()){
        if(min_diff> abs(arr1[i]-arr2[j])){
            min_diff = abs(arr1[i]-arr2[j]);
        }

        if(arr1[i]>arr2[j])
            j++;
        else
            i++;
    }
    return min_diff;
}

int main(){
    vector<int> arr1 = {1,3,15,11,2};
    vector<int> arr2 = {23,127,235,19,8};

    cout<<find_difference(arr1, arr2)<<"\n";

    return 0;
}