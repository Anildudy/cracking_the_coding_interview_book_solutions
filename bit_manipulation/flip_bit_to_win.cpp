#include<bits/stdc++.h>
using namespace std;


vector<int> getAlternateSequence(int n){
    vector<int> seq;
    int searchingFor = 0;
    int counter = 0;

    for(int i=0; i<sizeof(int)*8; i++){
        if((n&1)!= searchingFor){
            seq.push_back(counter);
            counter = 0;
            searchingFor = n&1;
        }
        n = n>>1;
        counter++;
    }
    seq.push_back(counter);
    return seq;
}

int getLongestSequence(vector<int> seq){
    int maxseq = 1;
    for(int i=0; i<seq.size(); i+=2){
        int zeroSeq = seq[i];
        //cout<<zeroSeq<<" ";
        int left = i-1>=0 ? seq[i-1]:0;
        int right = i+1<seq.size() ? seq[i+1]:0;

        int curr = 0;
        if(zeroSeq==1){
            curr = 1+left+right;
        }
        else if(zeroSeq>1){
            curr = 1 + max(left,right);
        }
        else if(zeroSeq==0){
            curr = max(left,right);
        }
        
        maxseq = max(maxseq, curr);
    }
    return maxseq;
}

int longestSequence(int no){
    if(no==-1)
        return sizeof(int)*8;
    vector<int> seq = getAlternateSequence(no);
    return getLongestSequence(seq);
}

int flip_bit(int n){
    int curr = 0;
    int prev = 0;
    int max_len = 1;
    while(n!=0){
        if(n&1 == 1){
            curr++;
        }
        else if(n&1 == 0){
            prev = n&2 == 0 ? 0: curr;
            curr = 0;
        }
        max_len = max(prev+curr+1, max_len);
        n >>= 1;
    }
    return max_len;
}

int main(){
    int n;
    cin>>n;
    cout<<flip_bit(n)<<"\n";

    return 0;
}