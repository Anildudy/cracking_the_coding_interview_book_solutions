#include<bits/stdc++.h>
using namespace std;

struct point{
    int height;
    int weight;

    point(int a, int b){
        height = a;
        weight = b;
    }
};

bool comp(point a, point b){
   if(a.height==b.height){
       return a.weight<b.weight;
   }
   return a.height<b.height;
}

// find longest increasing subsequece
int find_sequence(vector<point>& v){
    vector<int>dp(v.size()+1);
    dp[0] = 0;
    dp[1] = 1;
    for(int i=1; i<v.size(); i++){
        if(v[i].weight>v[i-1].weight)
            dp[i+1] = dp[i]+1;
        else
            dp[i+1] = 1;
    }
    return *max_element(dp.begin(),dp.end());
}

int main(){
    int t;
    cin>>t;
    vector<point> v;
    int i=0;
    while(t--){
        int h,w;
        cout<<"Enter height ";
        cin>>h;
        cout<<"Enter weight ";
        cin>>w;
        point p = point(h,w);
        v.push_back(p);
    }
    sort(v.begin(), v.end(),comp); // sort based on height and break tie using weight
    // for(point p : v)
    //     cout<<p.height<<" "<<p.weight<<"\n";

    cout<<find_sequence(v)<<"\n";

    return 0;
}