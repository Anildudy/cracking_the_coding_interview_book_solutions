#include<bits/stdc++.h>
using namespace std;

void group_anagrams(vector<string>& st){
  map<string, vector<string>> mp;
  for(string s: st){
    string val = s;
    sort(s.begin(), s.end());
    mp[s].push_back(val);
  }
  int index = 0;
  for(auto it = mp.begin(); it!= mp.end(); it++){
    for(string item : it->second)
      st[index++] = item;
  }
}


int main(){
  vector<string> st = {"abc", "ab", "jkd", "bac", "cab", "ba","def","acb"};
  group_anagrams(st);

  for(string s : st)
    cout<<s<<"\n";
}
