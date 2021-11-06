#include<bits/stdc++.h>
using namespace std;


void sorted_merge(vector<int> &arr1, vector<int> &arr2, int i, int j){
  int k = i+j-1;
  i--;
  j--;
  //cout<<i<<" "<<j<<" "<<k<<" ";
  while(j>=0){
    if(arr2[j]>= arr1[i]){
      arr1[k--] = arr2[j--];
    }
    else{
      arr1[k--] = arr1[i--];
    }
  }

  for(int i=0; i<arr1.size(); i++)
    cout<<arr1[i]<<" ";

}

int main(){
int n,m;
cin>>n>>m;

vector<int> arr1(n+m);
for(int i=0; i<n; i++)
  cin>>arr1[i];

vector<int> arr2(m);
for(int i=0; i<m; i++)
  cin>>arr2[i];

sorted_merge(arr1,arr2,n,m);

return 0;
}
