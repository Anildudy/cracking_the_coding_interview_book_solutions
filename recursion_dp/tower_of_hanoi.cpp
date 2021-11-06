#include<bits/stdc++.h>
using namespace std;
using namespace std::chrono;

void move_disk(stack<int>& source, stack<int>& destination){
    destination.push(source.top());
    source.pop();
    return;
}

void tower_of_hanoi(int n, stack<int>&source, stack<int>&destination, stack<int>&buffer){
    if(n<=0)
        return;
    tower_of_hanoi(n-1,source,buffer,destination);
    move_disk(source,destination);
    tower_of_hanoi(n-1,buffer,destination,source);
}

void print_stack(stack<int> st){
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<"\n";
    return;
}

int main(){
    stack<int> source;
    stack<int> buffer;
    stack<int> destination;
    for(int i=28; i>0; i--)
        source.push(i);
    
    cout<<"Source stack: ";
    print_stack(source);
    cout<<"Buffer stack: ";
    print_stack(buffer);
    cout<<"Destination stack: ";
    print_stack(destination);

    auto start = high_resolution_clock::now();
    tower_of_hanoi(28,source,destination,buffer);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop-start);
    cout<<"Time taken by this function : " <<duration.count()<<" milliseconds\n";

    cout<<"Source stack: ";
    print_stack(source);
    cout<<"Buffer stack: ";
    print_stack(buffer);
    cout<<"Destination stack: ";
    print_stack(destination);

    return 0;
}