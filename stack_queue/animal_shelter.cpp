#include<bits/stdc++.h>
using namespace std;

string dequeue_cat(list<string>&ls){
    if(ls.empty())
        return "Sorry! No animal available!!";

    for(auto it=ls.begin(); it!=ls.end(); it++){
        if(*it == "cat"){
            ls.erase(it);
            return "Here is your cat";
        }
    }
    return "No cat availabe!!";
}

string dequeue_dog(list<string>& ls){
    if(ls.empty())
        return "Sorry! No animal available!!";

    for(auto it = ls.begin(); it!=ls.end(); it++){
        if(*it == "dog"){
            ls.erase(it);
            return "Here is your dog";
        }
    }
    return "No dog available!!";
}

string dequeue_any(list<string>& ls){
    if(ls.empty())
        return "Sorry! no animal available!!";
    string v = ls.front();
    ls.pop_front();
    return "here is your animal " + v; 
}

string enqueue(list<string>& ls, string val){
    ls.push_back(val);
    return "pushed " + val;
}

int main(){
    list<string> ls;
    string input;
    while(cin>>input){
        if(input=="stop")
            break;
        cout<<enqueue(ls,input)<<"\n";
    }
    cout<<dequeue_any(ls)<<"\n";
    cout<<dequeue_any(ls)<<"\n";
    cout<<dequeue_cat(ls)<<"\n";
    cout<<dequeue_dog(ls)<<"\n";

    return 0;
}