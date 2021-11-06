#include<bits/stdc++.h>
using namespace std;

int count_of(string s, char c){
    int cnt = 0;
    for(int i=0; i<s.length(); i++){
        if(s[i]==c)
            cnt++;
    }
    return cnt;
}

string build_string(string pattern, string first, string second){
    string s = "";
    char c = pattern[0];
    for(int i=0; i<pattern.length(); i++){
        if(c==pattern[i])
            s += first;
        else
            s += second;
    }
    return s;
}

bool does_match(string pattern, string value){
    if(pattern.length()==0)
        return value.length()==0;

    char main_char = pattern[0];
    char alt_char = main_char=='a'?'b':'a';
    int size = value.length();

    int count_of_main = count_of(pattern, main_char);
    int count_of_alt = pattern.length() - count_of_main;
    int first_alt = pattern.find(alt_char);
    int max_main_size = size/count_of_main;

    for(int main_size=0; main_size<=max_main_size; main_size++){
        int remaining_length = size - main_size*count_of_main;
        string first = value.substr(0,main_size);
        if(count_of_alt==0 || remaining_length%count_of_alt==0){
            int alt_index = main_size*first_alt;
            int alt_size = count_of_alt==0 ? 0 : remaining_length/count_of_alt;
            string second = count_of_alt==0? "": value.substr(alt_index,alt_size);

            string tmp = build_string(pattern,first,second);
            if(tmp==value)
                return true;
        }
    }
    return false;
}

int main(){
    string pattern, value;
    cin>>pattern>>value;

    if(does_match(pattern, value))
        cout<<"Pattern match found!\n";
    else 
        cout<<"No match found!\n";

    return 0;
}