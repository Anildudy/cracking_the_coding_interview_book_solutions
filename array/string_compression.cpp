#include<bits/stdc++.h>
using namespace std;

string compress(string s){
    string st = "";
    int count = 1;
    for(int i=0; i<s.length(); i++){
        if(i==s.length()-1){
            st += s[i];
            st += to_string(count);
            break;
        }
        if(s[i]!=s[i+1]){
            st += s[i];
            st += to_string(count);
            count = 1;
            continue;
        }
        count++;
    }
    return s.length()<=st.length()? s:st;
}

int main(){
    string s = "aabccca";
    cout<<compress(s)<<"\n";
}