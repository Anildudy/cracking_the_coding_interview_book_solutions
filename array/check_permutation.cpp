#include<bits/stdc++.h>
using namespace std;

bool check(string s1, string s2){
  if(s1.length() != s2.length())
    return false;

  int arr[128];
  memset(arr,0,sizeof(arr));

  // for(int i=0; i<128; i++){
  //   cout<<arr[i]<<" ";
  // }
  for(int i=0; i<s1.length(); i++){
    arr[s1[i]] += 1;
    arr[s2[i]] -= 1;
  }

  for(int i=0; i<128; i++){
    if(arr[i]!=0){
      cout<<arr[i]<<" "<<i<<" "<<endl;
      return false;
    }
  }
  return true;
}

int main(){
  string s1,s2;
  cin>>s1>>s2;
  if(check(s1,s2))
    cout<<"Yes! they are permutation of each other\n";
  else
    cout<<"They are not permutation of each other!\n";

  return false;
}
