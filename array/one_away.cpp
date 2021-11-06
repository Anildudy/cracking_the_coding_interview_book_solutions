#include<bits/stdc++.h>
using namespace std;

bool check(string a, string b){
  int d = a.length()-b.length();
  d  = abs(d);
  //cout<<d<<"\n";
  if(d >1)
    return false;

  string s1 = a.length()<b.length()? a:b;
  string s2 = a.length()<b.length()? b:a;

  int idx1 = 0;
  int idx2 = 0;
  bool foundDifference = false;

  while(idx1<s1.length() && idx2<s2.length()){
    if(s1[idx1] != s2[idx2]){
      if(foundDifference)
        return false;
      foundDifference = true;

      if(s1.length()==s2.length())
        idx1++;
    }
    else{
      idx1++;
    }
    idx2++;
  }
 return true;
}


int main(){
  string a, b;
  cin>>a>>b;
  cout<<check(a,b)<<"\n";

  return 0;
}
