#include<bits/stdc++.h>
using namespace std;

bool isUnique(string s){
  bool arr[128];
  memset(arr, false, sizeof(arr));

  if(s.length()>128)
    return false;

  for(int i=0; i<s.length(); i++){
    if(arr[s[i]])
    return false;
    else
      arr[s[i]] = true;
  }
  return true;

}

int main(){
  string s;
  cin>>s;
  if(isUnique(s))
    cout<<"The string is unique!\n";
  else
    cout<<"The string is not unique!\n";
}
