#include<bits/stdc++.h>
using namespace std;

int binary_search(listy list, int low, int high, int target){
    int mid;
    while(low<=high){
        mid = (low+high)/2;
        int middleElement = list[mid];
        if(middleElement>target && middleElement==-1)
            high = mid-1;
        else if(middleElement<target)
            low = mid+1;
        else
            return mid;
    }
    return -1;
}

int search(listy list, int target){
    int index = 1;
    while(list[index]!=-1 && list[index]<target)
        index *= 2;
    return binary_search(list,index/2, index, target);
}

int main(){
    
    search(list,target);

return 0;
}