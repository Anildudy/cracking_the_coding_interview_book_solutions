#include<bits/stdc++.h>
using namespace std;

int main(){

  string st;
  getline(cin,st);
  transform(st.begin(),st.end(),st.begin(),::tolower);
  map<char,int>m;
  int s=0;
  for(int i=0; i<st.length(); i++){
    if(st[i] != ' '){
      m[st[i]]++;
      s++;
    }
  }

  int count = 0;
  for(auto it= m.begin(); it!= m.end(); it++){
    cout<<it->first<<" "<<it->second<<"\n";
    if(it->second == 1)
      count++;
  }
  if(s%2== 0 && count==0)
    cout<<"True"<<"\n";
  else if(s%2==0 && count>0)
    cout<<"False"<<"\n";
  else if(s%2!=0 && count==1)
    cout<<"True"<<"\n";
  else
    cout<<"False"<<"\n";
  return 0;
}
