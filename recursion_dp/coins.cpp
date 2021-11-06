#include<bits/stdc++.h>
using namespace std;
using namespace std::chrono;
#define ll long long int

ll count_ways_rec(int n,const int a, const int b,const int c ){
    if(n<0)
        return 0;
    if(n==0)
        return 1;
    
    return count_ways_rec(n-a,a,b,c) + count_ways_rec(n-b,a,b,c) + count_ways_rec(n-c,a,b,c);
}

ll count_ways_rec_dp(int n, vector<int>&dp, int a, int b, int c){
    if(n==0)
        return 1;
    if(n<0)
        return 0;
    if(dp[n]!=0)
        return dp[n];

    dp[n] = count_ways_rec_dp(n-a,dp,a,b,c) + count_ways_rec_dp(n-b,dp,a,b,c) + count_ways_rec_dp(n-c,dp,a,b,c);
    return dp[n];
}

ll count_ways_loop(int n, int a, int b, int c){
    vector<int> dp(n+1,0);
    int arr[] = {a,b,c};

    for(int i=1; i<=n; i++){
        for(int item : arr){
            if(i-item<0)
                break;
            else if(i-item==0)
                dp[i]++;
            else
                dp[i] += dp[i-item];
        }    
    }
    return dp[n];
}

int main(){
    int n;
    cin>>n;
    int a, b, c;
    cin>>a>>b>>c;
    
    auto start = high_resolution_clock::now();
    //cout<<count_ways_rec(n,a,b,c)<<"\n";
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop-start);
    cout<<"Time taken using only rec "<<duration.count()<<"\n";

    vector<int>dp(n+1,0);
    auto start1 = high_resolution_clock::now();
    cout<<count_ways_rec_dp(n,dp,a,b,c)<<"\n";
    auto stop1 = high_resolution_clock::now();
    auto duration1 = duration_cast<milliseconds>(stop1-start1);
    cout<<"Time taken using rec and dp "<<duration1.count()<<"\n";

    auto start2 = high_resolution_clock::now();
    cout<<count_ways_loop(n,a,b,c)<<"\n";
    auto stop2 = high_resolution_clock::now();
    auto duration2 = duration_cast<milliseconds>(stop2-start2);
    cout<<"Time taken using loop "<<duration2.count()<<"\n";

    return 0;
}