#include<bits/stdc++.h>
using namespace std;

int most_alive(vector<vector<int>> & years){
    vector<int> arr(100,0);
    for(auto item: years){
        arr[item[0]-1900]++;
        arr[item[1]-1900+1]--;
    }
    int mx = 0;
    int sum = 0;
    int idx = 0;
    for(int i=0; i<101; i++){
        sum += arr[i];
        if(sum>mx)
            idx = i;
        mx = max(mx,sum);
    }
    return idx+1900;
}

int main(){
    vector<vector<int>>years = {{1906,1977},{1905,1906}};
    cout<<most_alive(years)<<"\n";

    return 0;
}