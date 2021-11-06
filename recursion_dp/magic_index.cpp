#include<bits/stdc++.h>
using namespace std;

int find_index(int arr[],int low, int high){
    if(low>high)
        return -1;

    int mid = low + (high-low)/2;
    if(arr[mid]==mid)
        return mid;
    int mid_value = arr[mid];
    
    int leftIndex = min(mid_value,mid-1);
    int left = find_index(arr,low,leftIndex);
    if(left>=0)
        return left;

    int rightIndex = max(mid_value,mid+1);
    int right = find_index(arr,rightIndex,high);

    return right;
}

int main(){
    int arr[] = {1,2,2,2,3,5,7};
cout<<find_index(arr,0,5);

return 0;
}