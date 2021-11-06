#include<bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  string s;
  int len;
  cin>>len;
  string dummy;
  getline(cin,dummy);
  getline(cin, s);
  cout<<s<<" ";
  string res = "";
  for(int i=0; i<len; i++){
    //cout<<s[i]<<" "<<res<<"\n";
    if(s[i] == ' '){
      res += "%20";
    }
    else{
      res += s[i];
    }
  }
  cout<<res<<endl;

  return 0;
}
