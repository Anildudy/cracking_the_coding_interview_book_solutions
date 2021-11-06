#include<bits/stdc++.h>
using namespace std;

void sort(stack<int>& st){
    stack<int> tmp;
    if(st.empty())
        return;

    tmp.push(st.top());
    st.pop();

    while(!st.empty()){
        int element = st.top();
        if(element < tmp.top()){
            st.pop();
            while(!tmp.empty()){
                st.push(tmp.top());
                tmp.pop();
            }
            tmp.push(element);
        }
        else{
            tmp.push(st.top());
            st.pop();
        }
    }
    while(!tmp.empty()){
        st.push(tmp.top());
        tmp.pop();
    }

    return;
}

int main(){
    stack<int> st;
    st.push(1);
    st.push(4);
    st.push(2);
    st.push(3);
    st.push(5);

    sort(st);

    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<"\n";

    return 0;
}