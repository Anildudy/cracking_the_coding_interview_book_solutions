#include<bits/stdc++.h>
using namespace std;

int binary_search(string arr[], string s,int first, int last){
    if(first>last)
        return -1;
    int mid = (first+last)/2;

    if(arr[mid]==" "){
        int left = mid-1;
        int right = mid+1;
        while(true){
            if(right>last && left<first)
                return -1;
            else if(right<=last && arr[right]!=" "){
                mid = right;
                break;
            }
            else if(left>=first && arr[left]!=" "){
                mid = left;
                break;
            }
            left--;
            right++;
        }
    }

    if(arr[mid] == s)
        return mid;
    else if(arr[mid]<s)
        return binary_search(arr,s,mid+1,last);
    else
        return binary_search(arr,s,first, mid-1);
}

int main(){
    string arr[] = {"a","b", " "," "," "," ","b"};
    cout<<binary_search(arr,"b",0,6)<<"\n";
}