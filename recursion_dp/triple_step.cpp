#include<bits/stdc++.h>
using namespace std;

int no_of_steps(int n){
  std::vector<int> steps(n+1,0);
  std::vector<int> v = {1,2,3};

  for(int i=1; i<=n; i++){
    for(int s: v){
      if(i-s > 0){
        steps[i]+= steps[i-s]+1;
      }
      else if(i-s < 0)
        break;
      else{
        steps[i]++;
      }
    }
    cout<<steps[i]<<" ";
  }

  return steps[n];

}

int main(){
  int n;
  cin>>n;
  cout<<no_of_steps(n)<<"\n";
}
