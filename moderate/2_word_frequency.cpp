#include<iostream>
#include<vector>
#include<map>
using namespace std;

int main(){
    vector<string> v = {"ab", "hii", "hii", "bi", "ab"};
    
    map<string, int>mp;
    for(auto item: v){
        mp[item]++;
    }
    
    string input;
    while(cin>>input){
        if(input=="stop")
            break;
        if(mp.find(input)!=mp.end())
            cout<<mp[input]<<"\n";
        else{
            cout<<"Item not present\n";
        }
    }

    return 0;
}