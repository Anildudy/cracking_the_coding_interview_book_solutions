#include<bits/stdc++.h>
using namespace std;

int binary_search(int arr[], int n,int r, int low, int high, int target){
  if(low>high)
    return -1;

  int mid=low + (high-low)/2;
  int idx = mid+r;
  if(idx>=n)
    idx = idx-n;
  if(arr[idx] == target)
    return idx;
  if(arr[idx]>target)
    return binary_search(arr,n,r,low,mid-1,target);
  else
    return binary_search(arr,n,r,mid+1,high,target);
}


int main(){
  int n;
  cin>>n;
  int target;
  cin>>target;
  int arr[n];
  for(int i=0; i<n; i++)
    cin>>arr[i];

  int r= 0;
  for(int i=0; i<n-1; i++){
    if(arr[i+1]<arr[i]){
      r = i+1;
      break;
    }
  }
  //cout<<r<<"\n";

  cout<<binary_search(arr,n,r,0,n-1,target)<<endl;
}
